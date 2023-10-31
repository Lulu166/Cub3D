/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:22:24 by lucas             #+#    #+#             */
/*   Updated: 2023/10/31 13:55:44 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

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

char	*loop_map(t_game *game, char *line, int fd)
{
	int	i;

	while (1)
	{
		while (line && line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			if (line == NULL)
				return (NULL);
			game->line_count++;
		}
		i = -1;
		while (line[++i])
		{
			if (line[i] == '1' || line[i] == '0')
				return (line);
			else if (line[i] != ' ')
			{
				free(line);
				return (NULL);
			}
		}
	}
}

char	*find_map(t_game *game, int fd)
{
	char	*line;

	line = get_next_line(fd);
	game->line_count++;
	line = loop_map(game, line, fd);
	if (line != NULL)
		return (line);
	free(line);
	return (NULL);
}

char	*parse_line(t_game *game, char *line, char **map_tab, int i)
{
	if (check_line(line) == 1)
		map_tab[i] = ft_strdup(line);
	else
	{
		free_val_alloc(line, map_tab);
		map_error(game, 0, 0, 2);
	}
	return (map_tab[i]);
}

char	**allocate_map(t_game *game, int fd)
{
	int		i;
	char	**map_tab;
	char	*line;

	i = 0;
	line = find_map(game, fd);
	map_tab = calloc((game->map_size - game->line_count) + 2, sizeof(char *));
	if (map_tab == NULL)
	{
		free(line);
		map_error(game, 0, 0, 0);
	}
	while (line)
	{
		map_tab[i] = parse_line(game, line, map_tab, i);
		i++;
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			return (map_tab[i] = NULL, map_tab);
	}
	return (free(map_tab), NULL);
}
