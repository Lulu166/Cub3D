/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:22:44 by lucas             #+#    #+#             */
/*   Updated: 2023/08/19 11:15:29 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	empty_error(t_game *game, int i, int j)
{
	if (game->tab_map[i][j + 1] != '1'  && game->tab_map[i][j + 1] != '0')
		return (1);
	if (game->tab_map[i + 1][j + 1] != '1'  && game->tab_map[i + 1][j + 1] != '0')
		return (1);
	if (game->tab_map[i + 1][j] != '1'  && game->tab_map[i + 1][j] != '0')
		return (1);
	if (game->tab_map[i + 1][j - 1] != '1'  && game->tab_map[i + 1][j - 1] != '0')
		return (1);
	if (game->tab_map[i][j - 1] != '1'  && game->tab_map[i][j - 1] != '0')
		return (1);
	if (game->tab_map[i - 1][j - 1] != '1'  && game->tab_map[i - 1][j - 1] != '0')
		return (1);
	if (game->tab_map[i - 1][j] != '1'  && game->tab_map[i - 1][j] != '0')
		return (1);
	if (game->tab_map[i - 1][j + 1] != '1'  && game->tab_map[i - 1][j + 1] != '0')
		return (1);
	return (0);
}

int	skip_empty(t_game *game, int i, int *j)
{
	while (game->tab_map[i][*j] == '0')
	{
		if (empty_error(game, i, *j) == 1)
			map_error(game);
		(*j)++;
	}
	if (game->tab_map[i][*j] != '1')
		map_error(game);
	return (0);
}

int	skip_wall(t_game *game, int i, int *j)
{
	while (game->tab_map[i][*j] == '1')
		(*j)++;
	if (game->tab_map[i][*j] == '\n')
		return (2);
	return (0);
}

int	skip_space(t_game *game, int i, int *j)
{
	while (game->tab_map[i][*j] == ' ')
		(*j)++;
	if (game->tab_map[i][*j] == '\n')
		return (2);
	if (game->tab_map[i][*j] != '1')
		map_error(game);
	return (0);
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
		printf("%s", game->tab_map[i]);
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