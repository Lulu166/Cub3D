/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:21:35 by lucas             #+#    #+#             */
/*   Updated: 2023/10/12 17:12:28 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_mlx(t_game *game, int is_mlx)
{
	if (is_mlx >= 3)
		mlx_destroy_image(game->screen.mlx, game->data->img);
	if (is_mlx >= 2)
		mlx_destroy_window(game->screen.mlx, game->screen.win);
	mlx_destroy_display(game->screen.mlx);
	free(game->screen.mlx);
}

void	free_game(t_game *game, int is_map, int is_mlx)
{
	int	i;

	free(game->tex.no);
	free(game->tex.so);
	free(game->tex.ea);
	free(game->tex.we);
	if (is_map >= 1)
	{
		i = 0;
		while (game->tab_map[i])
		{
			free(game->tab_map[i]);
			i++;
		}
		free(game->tab_map);
	}
	if (is_map >= 2)
	{
		if (is_mlx >= 1)
			free_mlx(game, is_mlx);
		free(game->data);
	}
	if (is_map >= 3)
		free(game->ray);
}

void	map_error(t_game *game, int is_map, int is_mlx)
{
	ft_printf("Error\n");
	free_game(game, is_map, is_mlx);
	exit(1);
}

void	free_for_end(t_game *game)
{
	free_game(game, 3, 3);
	exit (0);
}
