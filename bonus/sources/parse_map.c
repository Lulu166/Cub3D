/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:22:44 by lucas             #+#    #+#             */
/*   Updated: 2023/10/31 16:14:01 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

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

int	fill_column_count(t_game *game)
{
	int	i;

	i = 0;
	game->column_count = malloc(sizeof(int) * map_size(game));
	if (!game->column_count)
		map_error(game, 1, 1, 0);
	while (game->tab_map[i] && i <= map_size(game))
	{
		game->column_count[i] = ft_strlen(game->tab_map[i]);
		i++;
	}
	return (1);
}
