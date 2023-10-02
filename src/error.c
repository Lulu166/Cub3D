/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:21:35 by lucas             #+#    #+#             */
/*   Updated: 2023/09/30 13:08:58 by luhumber         ###   ########.fr       */
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
	//free(game->tex.f);
	//free(game->tex.c);
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
}

void	map_error(t_game *game, int is_map)
{
	printf("Error\n");
	free_pack(game, is_map);
	exit(1);
}

void	free_for_end(t_game *game)
{
	free_pack(game, 1);
	exit (0);
}
