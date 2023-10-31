/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:21:35 by lucas             #+#    #+#             */
/*   Updated: 2023/10/31 12:54:08 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

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

void	free_for_end(t_game *game)
{
	free_game(game, 3, 3);
	exit (0);
}
