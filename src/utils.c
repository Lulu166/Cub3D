/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:35:43 by lucas             #+#    #+#             */
/*   Updated: 2023/09/28 11:46:51 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	skip_space(t_game *game, int i, int *j)
{
	while (game->tab_map[i][*j] == ' ')
		(*j)++;
	if (game->tab_map[i][*j] == '\n')
		return (2);
	if (game->tab_map[i][*j] != '1')
		map_error(game, 1);
	return (0);
}

int	compare_str(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while ((i <= len) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	valid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		|| line[i] == '\r' || line[i] == '\v' || line[i] == '\f')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	else
		return (0);
}
