/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:22:44 by lucas             #+#    #+#             */
/*   Updated: 2023/08/29 11:22:38 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player.nb_p = 0;
	game->player.color = 0xFFD700;
	while (game->tab_map[i])
	{
		j = 0;
		while (game->tab_map[i][j])
		{
			if (is_player(game, i, j) == 1)
			{
				game->player.nb_p++;
				game->player.x = j;
				game->player.y = i;
				game->tab_map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (game->player.nb_p != 1)
		return (0);
	return (1);
}

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
			map_error(game, 1);
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
		map_error(game, 1);
	if (player_pos(game) == 0)
		map_error(game, 1);
	return (0);
}
