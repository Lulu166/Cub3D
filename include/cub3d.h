/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:45:38 by lucas             #+#    #+#             */
/*   Updated: 2023/08/22 01:33:58 by luhumber         ###   ########.fr       */
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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpr;
	int		len;
	int		endian;
}	t_data;

typedef struct	s_window {
	void	*ref;
	int		x;
	int		y;
}	t_window;

typedef struct	s_screen {
	void		*mlx;
	void		*win;
	t_window	window;
}	t_screen;

typedef struct  s_texture {
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		*F;
	int		*C;
}   t_texture;

typedef struct	s_game {
	t_texture	texture;
	t_screen	screen;
	t_data		*data;
	char		*map;
	char		**tab_map;
	int			map_size;
	int			count;
}	t_game;

/***************TEXTURE***************/
void	allocate_texture(t_game *game, int fd);
int		valid_line(char *line);

/***************UTILS***************/
int	compare_str(char *s1, char *s2, int len);

/***************MAP***************/
char	**allocate_map(t_game *game, int fd);
int		parse_map(t_game *game);
int		skip_space(t_game *game, int i, int *j);
int		skip_wall(t_game *game, int i, int *j);
int		skip_empty(t_game *game, int i, int *j);
int		empty_error(t_game *game, int i, int j);

/***************WINDOW***************/
void    window_init(t_game *game);

/***************ERROR***************/
void	map_error(t_game *game);

#endif