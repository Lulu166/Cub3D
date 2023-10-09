/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:50:37 by lucas             #+#    #+#             */
/*   Updated: 2023/10/09 16:14:42 by luhumber         ###   ########.fr       */
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

int	check_rgb(t_game *game, char **line)
{
	if (comp_s("F", line[0], ft_strlen(line[0])) && game->tex.f == 0)
	{
		game->tex.f = allocate_rgb(game, line[1]);
		return (1);
	}
	else if (comp_s("F", line[0], ft_strlen(line[0])) && game->tex.f != 0)
		map_error(game, 0);
	if (comp_s("C", line[0], ft_strlen(line[0])) && game->tex.c == 0)
	{
		game->tex.c = allocate_rgb(game, line[1]);
		return (1);
	}
	else if (comp_s("C", line[0], ft_strlen(line[0])) && game->tex.c != 0)
		map_error(game, 0);
	map_error(game, 0);
	return (0);
}

int	check_texture(t_game *g, char **line)
{
	if (line[1] == NULL)
		map_error(g, 0);
	if (comp_s("NO", line[0], ft_strlen(line[0])) && g->tex.no == NULL)
		return (g->tex.no = ft_strdup(line[1]), 1);
	else if (comp_s("NO", line[0], ft_strlen(line[0])) && g->tex.no != NULL)
		map_error(g, 0);
	if (comp_s("SO", line[0], ft_strlen(line[0])) && g->tex.so == NULL)
		return (g->tex.so = ft_strdup(line[1]), 1);
	else if (comp_s("SO", line[0], ft_strlen(line[0])) && g->tex.so != NULL)
		map_error(g, 0);
	if (comp_s("WE", line[0], ft_strlen(line[0])) && g->tex.we == NULL)
		return (g->tex.we = ft_strdup(line[1]), 1);
	else if (comp_s("WE", line[0], ft_strlen(line[0])) && g->tex.we != NULL)
		map_error(g, 0);
	if (comp_s("EA", line[0], ft_strlen(line[0])) && g->tex.ea == NULL)
		return (g->tex.ea = ft_strdup(line[1]), 1);
	else if (comp_s("EA", line[0], ft_strlen(line[0])) && g->tex.ea != NULL)
		map_error(g, 0);
	return (0);
}

static void	free_val_alloc(char *line, char **split_line)
{
	free(line);
	free_tab(split_line);
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
		free_val_alloc(line, split_line);
		line = get_next_line(fd);
		split_line = ft_split_charset(line, " \t\n\r\v\f");
		game->count++;
	}
	free_val_alloc(line, split_line);
}
