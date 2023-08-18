/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:22:44 by lucas             #+#    #+#             */
/*   Updated: 2023/08/18 12:00:02 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	skip_space(t_game *game, int i, int *j)
{
	while (game->tab_map[i][*j] == ' ')
		(*j)++;
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
		while (game->tab_map[i][j])
		{
			if (game->tab_map[i][j] == ' ')
				skip_space(game, i, &j);
			while (game->tab_map[i][j] == '1' || game->tab_map[i][j] == '0')
				j++;
			if (game->tab_map[i][j] == ' ' && game->tab_map[i][j - 1] == '1')
				skip_space(game, i, &j);
			else if (game->tab_map[i][j] == ' ' && game->tab_map[i][j - 1] != '1')
				map_error(game);
			j++;
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