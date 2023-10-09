/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:21:35 by lucas             #+#    #+#             */
/*   Updated: 2023/10/09 14:09:57 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_game(t_game *game, int is_map)
{
	int	i;

	free(game->tex.no);
	free(game->tex.so);
	free(game->tex.ea);
	free(game->tex.we);
	if (is_map == 1)
	{
		i = 0;
		while (game->tab_map[i])
		{
			free(game->tab_map[i]);
			i++;
		}
		free(game->tab_map);
	}
	free(game->data);
	free(game->ray);
}

void	free_mlx(t_game *game)
{
	mlx_destroy_image(game->screen.mlx, game->data->img);
	mlx_destroy_window(game->screen.mlx, game->screen.win);
	mlx_destroy_display(game->screen.mlx);
	free(game->screen.mlx);
}

void	map_error(t_game *game, int is_map)
{
	printf("Error\n");
	free_game(game, is_map);
	exit(1);
}

void	free_for_end(t_game *game)
{
	free_mlx(game);
	free_game(game, 1);
	exit (0);
}
