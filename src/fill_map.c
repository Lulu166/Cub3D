/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:22:24 by lucas             #+#    #+#             */
/*   Updated: 2023/08/19 16:04:03 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\0')
			i++;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
				i++;
		else if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

char	*find_map(t_game *game, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	game->count++;
	while (1)
	{
		while (line && line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			if (line == NULL)
				return (NULL);
			game->count++;
		}
		i = 0;
		while (line[i])
		{
			if (line[i] == '1' || line[i] == '0')
				return (line);
			else if (line[i] != ' ')
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

char	**allocate_map(t_game *game, int fd)
{
	int		i;
	char	**map_tab;
	char	*line;

	i = 0;
	line = find_map(game, fd);
	map_tab = malloc(sizeof(char *) * ((game->map_size - game->count) + 1));
	while (line)
	{
		if (check_line(line) == 1)
			map_tab[i] = ft_strdup(line);
		else
		{
			free(line);
			map_error(game);
		}
		i++;
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			return (map_tab[i] = NULL, map_tab);
	}
	return (map_error(game), NULL);
}
