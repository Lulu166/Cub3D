/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:50:37 by lucas             #+#    #+#             */
/*   Updated: 2023/08/29 11:17:38 by luhumber         ###   ########.fr       */
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

int	check_rgb(t_game *game, char *line)
{
	if (compare_str("F", line, 1) && game->texture.f == NULL)
	{
		game->texture.f = allocate_rgb(game, line);
		return (1);
	}
	else if (compare_str("F", line, 1) && game->texture.f != NULL)
		map_error(game, 0);
	if (compare_str("C", line, 1) && game->texture.c == NULL)
	{
		game->texture.c = allocate_rgb(game, line);
		return (1);
	}
	else if (compare_str("C", line, 1) && game->texture.c != NULL)
		map_error(game, 0);
	map_error(game, 0);
	return (0);
}

int	check_texture(t_game *game, char *line)
{
	if (compare_str("NO", line, 2) && game->texture.no == NULL)
		return (game->texture.no = supp_space(line, 2), 1);
	else if (compare_str("NO", line, 2) && game->texture.no != NULL)
		map_error(game, 0);
	if (compare_str("SO", line, 2) && game->texture.so == NULL)
		return (game->texture.so = supp_space(line, 2), 1);
	else if (compare_str("SO", line, 2) && game->texture.so != NULL)
		map_error(game, 0);
	if (compare_str("WE", line, 2) && game->texture.we == NULL)
		return (game->texture.we = supp_space(line, 2), 1);
	else if (compare_str("WE", line, 2) && game->texture.we != NULL)
		map_error(game, 0);
	if (compare_str("EA", line, 2) && game->texture.ea == NULL)
		return (game->texture.ea = supp_space(line, 2), 1);
	else if (compare_str("EA", line, 2) && game->texture.ea != NULL)
		map_error(game, 0);
	return (0);
}

void	allocate_texture(t_game *game, int fd)
{
	char	*line;
	int		nb;

	nb = 0;
	line = get_next_line(fd);
	game->count++;
	while (nb < 6 && line)
	{
		if (line == NULL)
			return ;
		else if (line[0] != '\n')
		{
			if (valid_line(line) == 0)
			{
				if (check_texture(game, line))
					nb++;
				else if (check_rgb(game, line))
					nb++;
			}
		}
		free(line);
		line = get_next_line(fd);
		game->count++;
	}
	free(line);
}
