/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:21:35 by lucas             #+#    #+#             */
/*   Updated: 2023/10/05 11:35:18 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_pack(t_game *game, int is_map)
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

void	map_error(t_game *game, int is_map)
{
	printf("Error\n");
	free_pack(game, is_map);
	exit(1);
}

void	free_for_end(t_game *game)
{
	mlx_destroy_image(game->screen.mlx, game->data->img);
	mlx_destroy_window(game->screen.mlx, game->screen.win);
	mlx_destroy_display(game->screen.mlx);
	free(game->screen.mlx);
	free_pack(game, 1);
	exit (0);
}
