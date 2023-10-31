/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:57:54 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/31 12:59:30 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	check_extension(t_game *game, char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[--i] == 'm')
		if (str[--i] == 'p')
			if (str[--i] == 'x')
				if (str[--i] == '.')
					return ;
	map_error(game, 0, 0, 1);
}

int	check_name(char	*name)
{
	int	i;

	i = ft_strlen(name);
	if (name[--i] == 'b')
		if (name[--i] == 'u')
			if (name[--i] == 'c')
				if (name[--i] == '.')
					return (1);
	return (0);
}

int	is_directory(t_game *game, char *texture)
{
	int	fd;

	fd = open(texture, __O_DIRECTORY);
	if (fd != -1)
		map_error(game, 0, 0, 1);
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		map_error(game, 0, 0, 1);
	close(fd);
	return (0);
}

int	texture_exist(t_game *game)
{
	check_extension(game, game->tex.no);
	is_directory(game, game->tex.no);
	check_extension(game, game->tex.so);
	is_directory(game, game->tex.so);
	check_extension(game, game->tex.ea);
	is_directory(game, game->tex.ea);
	check_extension(game, game->tex.we);
	is_directory(game, game->tex.we);
	return (1);
}
