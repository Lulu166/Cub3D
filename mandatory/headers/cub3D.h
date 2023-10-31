/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:45:38 by lucas             #+#    #+#             */
/*   Updated: 2023/10/31 16:24:42 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define EMPTY 0
# define WALL 1
# define WIN_H 1080
# define WIN_W 1920

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

# include <../minilibx-linux/mlx.h>
# include <X11/X.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

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

typedef struct s_xpm {
	void	*xpm_tex;
	int		x;
	int		y;
	t_data	data;
}	t_xpm;

typedef struct s_texture {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	t_xpm	no_img;
	t_xpm	so_img;
	t_xpm	we_img;
	t_xpm	ea_img;
}	t_texture;

typedef struct s_pointf {
	float	x;
	float	y;
}	t_pointf;

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_player {
	enum e_position	pos;
	int				x;
	int				y;
	float			pos_x;
	float			pos_y;
	int				color;
	int				nb_p;
	int				left;
	int				top;
	int				right;
	int				down;
	char			orientation;
	int				rot_left;
	int				rot_right;
	int				mouse_right;
	int				mouse_left;
	int				click_left;
	int				click_right;
}	t_player;

typedef struct s_ray {
	double	pos_x;
	double	pos_y;
	int		dir_x;
	int		dir_y;
	float	dist;
	float	wall_size;
	bool	horizontal;
	float	opposit;
	float	adjacent;
	float	ray_angle;
	int		map_x;
	int		map_y;
	int		x;
}	t_ray;

typedef struct s_game {
	t_texture	tex;
	t_screen	screen;
	t_player	player;
	t_data		*data;
	t_ray		*ray;
	int			fd;
	char		*line;
	char		**split_line;
	int			is_map;
	char		*map;
	int			*column_count;
	float		collision[2];
	char		**tab_map;
	int			map_size;
	int			line_count;
	int			lenght;
	int			height;
	float		angle;
	float		shift;
	float		sin_angle;
	float		cos_angle;
	int			mini_map;
	int			nb_xpm;
}	t_game;

/***************TEXTURE***************/
int		check_name(char	*name);
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
void	free_val_alloc(char *line, char **split_line);
int		to_skip(char *line);
int		map_size(t_game *game);
int		to_hexa(int nb);
int		convert_value(int *tab);

/***************RAYCASTING***************/

void	init_ray(t_game *g, t_pointf *xy_v, t_pointf *xy_h);
float	check_vertical(t_game *game, t_pointf *xy);
float	check_horizontal(t_game *game, t_pointf *xy);
int		fill_column_count(t_game *game);
float	horizontal_pos(t_game *game, t_pointf *xy);
float	horizontal_neg(t_game *game, t_pointf *xy);
float	vertical_pos(t_game *game, t_pointf *xy);
float	vertical_neg(t_game *game, t_pointf *xy);
int		set_start_value(t_game *game);

/***************MAP***************/
char	**allocate_map(t_game *game, int fd);
int		parse_map(t_game *game);
int		skip_space(t_game *game, int i, int *j);
int		skip_wall(t_game *game, int i, int *j);
int		skip_empty(t_game *game, int i, int *j);
int		empty_error(t_game *game, int i, int j);
int		is_empty(t_game *game, int i, int j);
int		is_player(t_game *game, int i, int j);
void	init_player(t_game *game, int i, int j);
int		player_pos(t_game *game);

/***************WINDOW***************/
void	window_init(t_game *game);

/***************MINI_MAP***************/
void	mini_map(t_game *game);
void	game_init(t_game *game, char *arg);

/***************HOOKS***************/
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		mouse_click(int button, int x, int y, t_game *game);
int		mouse_hook(int x, int y, t_game *game);

/***************MOVEMENT***************/
int		can_move(t_game *game);
int		can_turn(t_game *game);
int		can_mouse(t_game *game);

/***************PIXELS***************/
void	my_mlx_pixel_put(t_data *data, double x, double y, int color);
int		my_pixel_get(t_data *data, int x, int y);
int		get_text_ns(t_game *game, int *y, long wall_size);
int		get_text_we(t_game *game, int *y, long wall_size);
void	draw_ceilling_floor(t_game *game, int *y, int y_max, int color);
void	draw_square(t_game *game, int height, int len, int color);
void	draw_circle(t_game *game, int y, int x, int color);
void	draw_wall(t_game *game, int *y, int y_max, int color);
void	draw_map(t_game *game);

/***************ERROR***************/
void	texture_problems(t_game *game, char **line);
void	map_error(t_game *game, int is_map, int is_mlx, int message);
void	free_for_end(t_game *game);
void	free_game(t_game *game, int is_map, int is_mlx);

#endif
