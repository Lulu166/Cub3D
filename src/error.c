/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:21:35 by lucas             #+#    #+#             */
/*   Updated: 2023/08/17 23:47:05 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    free_pack(t_game *game)
{
	int i;

	free(game->texture.NO);
	free(game->texture.SO);
	free(game->texture.EA);
	free(game->texture.WE);
	free(game->texture.F);
	free(game->texture.C);
	i = 0;
	if (game->tab_map)
	{
		while (game->tab_map[i])
			free(game->tab_map[i++]);
		free(game->tab_map);
	}
}

void    map_error(t_game *game)
{
	printf("Error\n");
	free_pack(game);
	exit(1);
}
