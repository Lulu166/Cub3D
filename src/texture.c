/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:50:37 by lucas             #+#    #+#             */
/*   Updated: 2023/08/14 21:05:10 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int parse_texture(t_game *game, char *line)
{
}

int check_texture(t_game *game, char *line)
{
	if (!game->texture.NO && compare_str("NO", line))
		return (game->texture.NO = ft_strdup(line), 1);
	else if (!game->texture.SO && compare_str("SO", line))
		return (game->texture.SO = ft_strdup(line), 1);
	else if (!game->texture.WE && compare_str("WE", line))
		return (game->texture.WE = ft_strdup(line), 1);
	else if (!game->texture.EA && compare_str("EA", line))
		return (game->texture.EA = ft_strdup(line), 1);
	else if (!game->texture.F && compare_str("F", line))
		return (game->texture.F = ft_strdup(line), 1);
	else if (!game->texture.C && compare_str("C", line))
		return (game->texture.C = ft_strdup(line), 1);
    else
        return (0);
}

void	allocate_texture(t_game *game, int fd)
{
	char	*line;
    int     nb_text;

    nb_text = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return ;
	while (line)
	{
		if (line == NULL)
			return ;
		check_texture(game, line);
		free(line);
		line = get_next_line(fd);
	}
}