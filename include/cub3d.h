/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:45:38 by lucas             #+#    #+#             */
/*   Updated: 2023/09/05 14:19:19 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define EMPTY 0
# define WALL 1


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
	int		*f;
	int		*c;
}	t_texture;

typedef struct s_player {
	enum e_position	pos;
	int				x;
	int				y;
	int				lenght;
	int				height;
	int				color;
	int				nb_p;
	int				left;
	int				top;
	int				right;
	int				down;
}	t_player;

typedef struct s_game {
	t_texture	texture;
	t_screen	screen;
	t_player	player;
	t_data		*data;
	char		*map;
	char		**tab_map;
	int			map_size;
	int			count;
	int			lenght;
	int			height;
}	t_game;

/***************TEXTURE***************/
void	allocate_texture(t_game *game, int fd);
int		valid_line(char *line);
char	*supp_space(char *line, int to_supress);
int		*allocate_rgb(t_game *game, char *line);

/***************UTILS***************/
int		compare_str(char *s1, char *s2, int len);

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

/***************MOVEMENT***************/
int		can_move(t_game *game);

/***************PIXELS***************/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_square(t_game *game, int height, int len, int color);
void	draw_circle(t_game *game, int y, int x, int color);

/***************ERROR***************/
void	map_error(t_game *game, int is_map);
void	free_for_end(t_game *game);

#endif