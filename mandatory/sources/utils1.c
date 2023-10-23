/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:24:02 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/23 12:55:19 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	to_skip(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\r' && line[i] != '\v' && line[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}

char	*supp_space(char *line, int to_supress)
{
	int		i;
	char	*cpy;

	i = 0;
	while (line[to_supress] == ' ')
		to_supress++;
	cpy = malloc(sizeof(char) * (ft_strlen(line) - to_supress) + 1);
	if (!cpy)
		return (NULL);
	while (line[to_supress] && line[to_supress] != '\n')
	{
		cpy[i] = line[to_supress];
		i++;
		to_supress++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	map_size(t_game *game)
{
	int	i;

	i = 0;
	while (game->tab_map[i])
		i++;
	return (i);
}
