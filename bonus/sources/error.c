/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:21:35 by lucas             #+#    #+#             */
/*   Updated: 2023/10/31 13:48:25 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	texture_problems(t_game *game, char **line)
{
	free(game->line);
	free_tab(line);
	map_error(game, 0, 0, 3);
}

void	error_message(int message)
{
	if (message == 0)
		ft_printf("Malloc error\n");
	else if (message == 1)
		ft_printf("File error\n");
	else if (message == 2)
		ft_printf("Map error\n");
	else if (message == 3)
		ft_printf("Texture error\n");
	else if (message == 4)
		ft_printf("Mlx error\n");
}

void	map_error(t_game *game, int is_map, int is_mlx, int message)
{
	if (is_map == 0)
		close(game->fd);
	ft_printf("Error\n");
	error_message(message);
	free_game(game, is_map, is_mlx);
	exit(1);
}
