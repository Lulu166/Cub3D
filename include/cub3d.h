/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:45:38 by lucas             #+#    #+#             */
/*   Updated: 2023/08/18 11:29:23 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define EMPTY 0
# define WALL 1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

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
	char		*map;
	char		**tab_map;
	int			map_size;
	int			count;
}	t_game;

/***************TEXTURE***************/
void	allocate_texture(t_game *game, int fd);

/***************UTILS***************/
int	compare_str(char *s1, char *s2, int len);

/***************MAP***************/
char	**allocate_map(t_game *game, int fd);
int		parse_map(t_game *game);

/***************ERROR***************/
void	map_error(t_game *game);

#endif