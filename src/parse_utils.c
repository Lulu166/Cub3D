/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:18:45 by lucas             #+#    #+#             */
/*   Updated: 2023/08/27 12:13:16 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_player(t_game *game, int i, int j)
{
	if (game->tab_map[i][j] == 'N' || game->tab_map[i][j] == 'S' || game->tab_map[i][j] == 'E' || game->tab_map[i][j] == 'W')
		return (1);
	return (0);
}

int	is_empty(t_game *game, int i, int j)
{
	if (game->tab_map[i][j] == '0' || is_player(game, i, j) == 1)
		return (1);
	return (0);
}

int	empty_error(t_game *game, int i, int j)
{
	if (game->tab_map[i][j + 1] != '1'  && is_empty(game, i, j + 1) != 1)
		return (1);
	if (game->tab_map[i + 1][j + 1] != '1'  && is_empty(game, i + 1, j + 1) != 1)
		return (1);
	if (game->tab_map[i + 1][j] != '1'  && is_empty(game, i + 1, j) != 1)
		return (1);
	if (game->tab_map[i + 1][j - 1] != '1'  && is_empty(game, i + 1, j - 1) != 1)
		return (1);
	if (game->tab_map[i][j - 1] != '1'  && is_empty(game, i, j - 1) != 1)
		return (1);
	if (game->tab_map[i - 1][j - 1] != '1'  && is_empty(game, i - 1, j - 1) != 1)
		return (1);
	if (game->tab_map[i - 1][j] != '1'  && is_empty(game, i - 1, j) != 1)
		return (1);
	if (game->tab_map[i - 1][j + 1] != '1'  && is_empty(game, i - 1, j + 1) != 1)
		return (1);
	return (0);
}

int	skip_empty(t_game *game, int i, int *j)
{
	while (is_empty(game, i, *j) == 1)
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
