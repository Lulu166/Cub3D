/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:22:44 by lucas             #+#    #+#             */
/*   Updated: 2023/10/17 11:48:13 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_player(t_game *game, int i, int j)
{
	game->player.color = 0xFFD700;
	game->player.nb_p++;
	game->player.x = j;
	game->player.y = i;
	game->player.posy = game->player.y * 16;
	game->player.posx = game->player.x * 16;
	game->player.top = 0;
	game->player.right = 0;
	game->player.down = 0;
	game->player.left = 0;
	game->player.mouse_left = 0;
	game->player.mouse_right = 0;
	game->player.click_left = 0;
	game->player.click_right = 0;
	game->player.rotLeft = 0;
	game->player.rotRight = 0;
	game->tab_map[i][j] = '0';
}

int	player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player.nb_p = 0;
	while (game->tab_map[i])
	{
		j = 0;
		while (game->tab_map[i][j])
		{
			if (is_player(game, i, j) == 1)
				init_player(game, i, j);
			j++;
		}
		i++;
	}
	if (game->player.nb_p != 1)
		return (0);
	return (1);
}

void	algo_parse(t_game *game, int i, int j)
{
	if (game->tab_map[i][j] != '1' && game->tab_map[i][j] != '\0')
		map_error(game, 1, 0, 2);
	while (game->tab_map[i][j])
	{
		if (skip_wall(game, i, &j) == 2)
			break ;
		if (game->tab_map[i][j] == '0' || is_player(game, i, j))
			skip_empty(game, i, &j);
		else if (game->tab_map[i][j] == ' ')
			if (skip_space(game, i, &j) == 2)
				break ;
	}
}

int	map_closed(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->tab_map[i] && game->tab_map[i][0] != '\0')
	{
		j = 0;
		if (game->tab_map[i][j] == ' ')
			skip_space(game, i, &j);
		if (game->tab_map[i][j] != '\n')
			algo_parse(game, i, j);
		i++;
	}
	return (0);
}

int	parse_map(t_game *game)
{
	if (map_closed(game))
		map_error(game, 1, 0, 2);
	if (player_pos(game) == 0)
		map_error(game, 1, 0, 2);
	return (0);
}
