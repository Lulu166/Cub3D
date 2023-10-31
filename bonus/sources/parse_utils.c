/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:18:45 by lucas             #+#    #+#             */
/*   Updated: 2023/10/31 15:41:20 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	is_player(t_game *game, int i, int j)
{
	if (game->tab_map[i][j] == 'N')
		return (game->player.pos = no, 1);
	else if (game->tab_map[i][j] == 'S')
		return (game->player.pos = so, 1);
	else if (game->tab_map[i][j] == 'E')
		return (game->player.pos = ea, 1);
	else if (game->tab_map[i][j] == 'W')
		return (game->player.pos = we, 1);
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
	if (i + 1 >= map_size(game))
		return (1);
	if (i - 1 < 0)
		return (1);
	if (j < 0)
		return (1);
	if ((j) >= (int)ft_strlen(game->tab_map[i + 1]))
		return (1);
	if (game->tab_map[i][j + 1] == '\n')
		return (1);
	if (game->tab_map[i][j + 1] != '1' && is_empty(game, i, j + 1) != 1)
		return (1);
	if (game->tab_map[i + 1][j] != '1' && is_empty(game, i + 1, j) != 1)
		return (1);
	if (game->tab_map[i][j - 1] != '1' && is_empty(game, i, j - 1) != 1)
		return (1);
	if (game->tab_map[i - 1][j] != '1' && is_empty(game, i - 1, j) != 1)
		return (1);
	return (0);
}

int	skip_empty(t_game *game, int i, int *j)
{
	while (is_empty(game, i, *j) == 1)
	{
		if (empty_error(game, i, *j) == 1)
			map_error(game, 1, 0, 2);
		(*j)++;
	}
	if (game->tab_map[i][*j] != '1')
		map_error(game, 1, 0, 2);
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
