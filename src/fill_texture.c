/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:50:37 by lucas             #+#    #+#             */
/*   Updated: 2023/08/27 19:25:30 by luhumber         ###   ########.fr       */
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

int	check_RGB(t_game *game, char *line)
{
	if (compare_str("F", line, 1) && game->texture.F == NULL)
	{
		game->texture.F = allocate_RGB(game, line);
		return (1);	
	}
	else if (compare_str("F", line, 1) && game->texture.F != NULL)
		map_error(game, 0);
	if (compare_str("C", line, 1) && game->texture.C == NULL)
	{
		game->texture.C = allocate_RGB(game, line);
		return (1);
	}
	else if (compare_str("C", line, 1) && game->texture.C != NULL)
		map_error(game, 0);
	map_error(game, 0);
	return (0);
}

int check_texture(t_game *game, char *line)
{
	if (compare_str("NO", line, 2) && game->texture.NO == NULL)
		return (game->texture.NO = supp_space(line, 2), 1);
	else if (compare_str("NO", line, 2) && game->texture.NO != NULL)
		map_error(game, 0);
	if (compare_str("SO", line, 2) && game->texture.SO == NULL)
		return (game->texture.SO = supp_space(line, 2), 1);
	else if (compare_str("SO", line, 2) && game->texture.SO != NULL)
		map_error(game, 0);
	if (compare_str("WE", line, 2) && game->texture.WE == NULL)
		return (game->texture.WE = supp_space(line, 2), 1);
	else if (compare_str("WE", line, 2) && game->texture.WE != NULL)
		map_error(game, 0);
	if (compare_str("EA", line, 2) && game->texture.EA == NULL)
		return (game->texture.EA = supp_space(line, 2), 1);	
	else if (compare_str("EA", line, 2) && game->texture.EA != NULL)
		map_error(game, 0);
	return (0);
}

void	allocate_texture(t_game *game, int fd)
{
	char	*line;
    int     nb;

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
				else if (check_RGB(game, line))
					nb++;
			}
		}
		free(line);
		line = get_next_line(fd);
		game->count++;
	}
	free(line);
}
