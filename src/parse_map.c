/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:22:44 by lucas             #+#    #+#             */
/*   Updated: 2023/08/19 11:39:04 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	map_closed(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->tab_map[i])
	{
		j = 0;
		if (game->tab_map[i][j] == ' ')
			skip_space(game, i, &j);
		if (game->tab_map[i][j] != '1')
			map_error(game);
		while (game->tab_map[i][j])
		{
			if (skip_wall(game, i, &j) == 2)
				break ;
			if (game->tab_map[i][j] == '0')
				skip_empty(game, i, &j);
			else if (game->tab_map[i][j] == ' ')
				if (skip_space(game, i, &j) == 2)
					break ;
		}
		i++;
	}
	return (0);
}

int	parse_map(t_game *game)
{
	if (map_closed(game))
		map_error(game);
	return (0);
}