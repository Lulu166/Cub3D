/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:45:38 by lucas             #+#    #+#             */
/*   Updated: 2023/10/09 16:29:38 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define EMPTY 0
# define WALL 1
# define WIN_H 1600
# define WIN_W 1600

# ifdef __APPLE__
#  define LEFT_ARROW_KEY 123
#  define RIGHT_ARROW_KEY 124
#  define UP_ARROW_KEY 126
#  define DOWN_ARROW_KEY 125
#  define W_LOWER_KEY 13
#  define S_LOWER_KEY 1
#  define A_LOWER_KEY 0
#  define D_LOWER_KEY 2
#  define ESC_KEY 53
#  define F5_KEY 96
#  define M_KEY 46
#  define P_KEY 35
#  define SPACE_KEY 49
# else
#  define LEFT_ARROW_KEY 65361
#  define RIGHT_ARROW_KEY 65363
#  define UP_ARROW_KEY 65362
#  define DOWN_ARROW_KEY 65364
#  define W_LOWER_KEY 119
#  define S_LOWER_KEY 115
#  define A_LOWER_KEY 97
#  define D_LOWER_KEY 100
#  define SPACE_KEY 32
#  define ESC_KEY 65307
#  define F5_KEY 65474
#  define M_KEY 109
#  define P_KEY 112
# endif

//# include <../mlx/mlx.h>
# include <../minilibx-linux/mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

enum e_position {no, so, ea, we};

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpr;
	int		len;
	int		endian;
}	t_data;

typedef struct s_window {
	void	*ref;
	int		x;
	int		y;
}	t_window;

typedef struct s_screen {
	void		*mlx;
	void		*win;
	t_window	window;
}	t_screen;

typedef struct s_texture {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
}	t_texture;

typedef struct s_player {
	enum e_position	pos;
	int				x;
	int				y;
	double			posx;
	double			posy;
	int				color;
	int				nb_p;
	int				left;
	int				top;
	int				right;
	int				down;
	int				rotLeft;
	int				rotRight;
}	t_player;

typedef struct s_ray {
	double posX;
	double posY;
	int	mapX;
	int	mapY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double raydirX;
	double raydirY;
	double lengthray_X;
	double lengthray_Y;
	double deltaX;
	double deltaY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	perpWallDist;
	int		DrawStart;
	int		DrawEnd;
	double time;
	double old_time;
}	t_ray;

typedef struct s_game {
	t_texture	tex;
	t_screen	screen;
	t_player	player;
	t_data		*data;
	t_ray		*ray;
	char		*map;
	char		**tab_map;
	int			map_size;
	int			count;
	int			lenght;
	int			height;
	double		angle;
	double		shift;
	double		sin_angle;
	double		cos_angle;
	int			mini_map;
}	t_game;

/***************TEXTURE***************/
void	allocate_texture(t_game *game, int fd);
int		valid_line(char *line);
char	*supp_space(char *line, int to_supress);
int		allocate_rgb(t_game *game, char *line);

/***************UTILS***************/
int		comp_s(char *s1, char *s2, int len);
void	init_ray_struct(t_game *g);
int		get_size(t_game *game);
int		texture_exist(t_game *game);
void	free_tab(char **split);

/***************RAYCASTING***************/

void	ray_casting(t_game *game);
void	throw_ray(t_game *game, double x_start, double y_start, double angle);


/***************MAP***************/
char	**allocate_map(t_game *game, int fd);
int		parse_map(t_game *game);
int		skip_space(t_game *game, int i, int *j);
int		skip_wall(t_game *game, int i, int *j);
int		skip_empty(t_game *game, int i, int *j);
int		empty_error(t_game *game, int i, int j);
int		is_empty(t_game *game, int i, int j);
int		is_player(t_game *game, int i, int j);

/***************WINDOW***************/
void	window_init(t_game *game);

/***************MINI_MAP***************/
void	mini_map(t_game *game);
void	game_init(t_game *game, char *arg);

/***************HOOKS***************/
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);

/***************MOVEMENT***************/
int		can_move(t_game *game);
int		can_turn(t_game *game);

/***************PIXELS***************/
void	my_mlx_pixel_put(t_data *data, double x, double y, int color);
void	draw_square(t_game *game, int height, int len, int color);
void	draw_circle(t_game *game, int y, int x, int color);

/***************ERROR***************/
void	map_error(t_game *game, int is_map);
void	free_for_end(t_game *game);

#endif
