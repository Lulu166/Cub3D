/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:50:37 by lucas             #+#    #+#             */
/*   Updated: 2023/09/28 12:48:43 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*supp_space(char *line, int to_supress)
{
	int		i;
	char	*cpy;

	i = 0;
	while (line[to_supress] == ' ')
		to_supress++;
	cpy = malloc(sizeof(char) * (ft_strlen(line) + to_supress));
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

int	check_rgb(t_game *game, char **line)
{
	if (compare_str("F", line[0], ft_strlen(line[0])) && game->tex.f == NULL)
	{
		game->tex.f = allocate_rgb(game, line[1]);
		return (1);
	}
	else if (compare_str("F", line[0], ft_strlen(line[0])) && game->tex.f != NULL)
		map_error(game, 0);
	if (compare_str("C", line[0], ft_strlen(line[0])) && game->tex.c == NULL)
	{
		game->tex.c = allocate_rgb(game, line[1]);
		return (1);
	}
	else if (compare_str("C", line[0], ft_strlen(line[0])) && game->tex.c != NULL)
		map_error(game, 0);
	map_error(game, 0);
	return (0);
}

int	check_texture(t_game *game, char **line)
{
	if (compare_str("NO", line[0], ft_strlen(line[0])) && game->tex.no == NULL)
		return (game->tex.no = ft_strdup(line[1]), 1);
	else if (compare_str("NO", line[0], ft_strlen(line[0])) && game->tex.no != NULL)
		map_error(game, 0);
	if (compare_str("SO", line[0], ft_strlen(line[0])) && game->tex.so == NULL)
		return (game->tex.so = ft_strdup(line[1]), 1);
	else if (compare_str("SO", line[0], ft_strlen(line[0])) && game->tex.so != NULL)
		map_error(game, 0);
	if (compare_str("WE", line[0], ft_strlen(line[0])) && game->tex.we == NULL)
		return (game->tex.we = ft_strdup(line[1]), 1);
	else if (compare_str("WE", line[0], ft_strlen(line[0])) && game->tex.we != NULL)
		map_error(game, 0);
	if (compare_str("EA", line[0], ft_strlen(line[0])) && game->tex.ea == NULL)
		return (game->tex.ea = ft_strdup(line[1]), 1);
	else if (compare_str("EA", line[0], ft_strlen(line[0])) && game->tex.ea != NULL)
		map_error(game, 0);
	return (0);
}

void	free_tab(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return ;
}

void	allocate_texture(t_game *game, int fd)
{
	char	*line;
	char	**split_line;
	int		nb;

	nb = 0;
	line = get_next_line(fd);
	split_line = ft_split_charset(line, " \t\n\r\v\f");
	game->count++;
	while (nb < 6 && split_line)
	{
		if (split_line == NULL)
			return ;
		else if (split_line[0][0] != '\n')
		{
			if (check_texture(game, split_line))
				nb++;
			else if (check_rgb(game, split_line))
				nb++;
		}
		free_tab(split_line);
		free(line);
		line = get_next_line(fd);
		split_line = ft_split_charset(line, " \t\n\r\v\f");
		game->count++;
	}
	free(line);
	free_tab(split_line);
}
