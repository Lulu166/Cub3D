/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:47:19 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/31 13:48:11 by luhumber         ###   ########.fr       */
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

void	free_texture(t_game *game)
{
	free(game->tex.no);
	free(game->tex.so);
	free(game->tex.ea);
	free(game->tex.we);
	if (game->nb_xpm >= 1)
		mlx_destroy_image(game->screen.mlx, game->tex.no_img.xpm_tex);
	if (game->nb_xpm >= 2)
		mlx_destroy_image(game->screen.mlx, game->tex.so_img.xpm_tex);
	if (game->nb_xpm >= 3)
		mlx_destroy_image(game->screen.mlx, game->tex.we_img.xpm_tex);
	if (game->nb_xpm >= 4)
		mlx_destroy_image(game->screen.mlx, game->tex.ea_img.xpm_tex);
}

void	free_game(t_game *game, int is_map, int is_mlx)
{
	int	i;

	free_texture(game);
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
		free(game->column_count);
		if (is_mlx >= 1)
			free_mlx(game, is_mlx);
		free(game->data);
	}
	if (is_map >= 3)
		free(game->ray);
}

void	free_for_end(t_game *game)
{
	free_game(game, 3, 3);
	exit (0);
}
