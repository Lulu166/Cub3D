/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:50:37 by lucas             #+#    #+#             */
/*   Updated: 2023/10/17 11:47:34 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_rgb(t_game *game, char **line)
{
	if (comp_s("F", line[0], ft_strlen(line[0])) && game->tex.f == 0)
	{
		game->tex.f = allocate_rgb(game, line[1]);
		return (1);
	}
	else if (comp_s("F", line[0], ft_strlen(line[0])) && game->tex.f != 0)
		map_error(game, 0, 0, 3);
	if (comp_s("C", line[0], ft_strlen(line[0])) && game->tex.c == 0)
	{
		game->tex.c = allocate_rgb(game, line[1]);
		return (1);
	}
	else if (comp_s("C", line[0], ft_strlen(line[0])) && game->tex.c != 0)
		map_error(game, 0, 0, 3);
	map_error(game, 0, 0, 3);
	return (0);
}

int	check_texture(t_game *g, char **line)
{
	if (line[1] == NULL)
		map_error(g, 0, 0, 3);
	if (comp_s("NO", line[0], ft_strlen(line[0])) && g->tex.no == NULL)
		return (g->tex.no = ft_strdup(line[1]), 1);
	else if (comp_s("NO", line[0], ft_strlen(line[0])) && g->tex.no != NULL)
		map_error(g, 0, 0, 3);
	if (comp_s("SO", line[0], ft_strlen(line[0])) && g->tex.so == NULL)
		return (g->tex.so = ft_strdup(line[1]), 1);
	else if (comp_s("SO", line[0], ft_strlen(line[0])) && g->tex.so != NULL)
		map_error(g, 0, 0, 3);
	if (comp_s("WE", line[0], ft_strlen(line[0])) && g->tex.we == NULL)
		return (g->tex.we = ft_strdup(line[1]), 1);
	else if (comp_s("WE", line[0], ft_strlen(line[0])) && g->tex.we != NULL)
		map_error(g, 0, 0, 3);
	if (comp_s("EA", line[0], ft_strlen(line[0])) && g->tex.ea == NULL)
		return (g->tex.ea = ft_strdup(line[1]), 1);
	else if (comp_s("EA", line[0], ft_strlen(line[0])) && g->tex.ea != NULL)
		map_error(g, 0, 0, 3);
	return (0);
}

int	all_check(t_game *game, char **split_line, int *nb, char *line)
{
	if (check_texture(game, split_line))
		(*nb)++;
	else if (check_rgb(game, split_line))
		(*nb)++;
	if (*nb == 6)
		return (free_val_alloc(line, split_line), 1);
	return (0);
}

char	*pass_empty(t_game *game, char *line, int fd)
{
	line = get_next_line(fd);
	if (line == NULL)
		map_error(game, 0, 0, 3);
	while (to_skip(line) == 0)
	{
		game->count++;
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			map_error(game, 0, 0, 3);
	}
	return (line);
}

void	allocate_texture(t_game *game, int fd)
{
	char	*line;
	char	**split_line;
	int		nb;

	nb = 0;
	line = NULL;
	line = pass_empty(game, line, fd);
	split_line = ft_split_charset(line, " \t\n\r\v\f");
	game->count++;
	while (nb < 6 && split_line)
	{
		if (split_line == NULL)
			map_error(game, 0, 0, 3);
		else if (split_line[0][0] != '\n')
			if (all_check(game, split_line, &nb, line) == 1)
				return ;
		free_val_alloc(line, split_line);
		line = pass_empty(game, line, fd);
		split_line = ft_split_charset(line, " \t\n\r\v\f");
		game->count++;
	}
	free_val_alloc(line, split_line);
}
