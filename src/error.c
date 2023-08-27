/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:21:35 by lucas             #+#    #+#             */
/*   Updated: 2023/08/27 19:27:24 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    free_pack(t_game *game, int is_map)
{
	int i;

	free(game->texture.NO);
	free(game->texture.SO);
	free(game->texture.EA);
	free(game->texture.WE);
	free(game->texture.F);
	free(game->texture.C);
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

void    map_error(t_game *game, int is_map)
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
