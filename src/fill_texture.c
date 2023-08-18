/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:50:37 by lucas             #+#    #+#             */
/*   Updated: 2023/08/17 23:49:14 by lucas            ###   ########.fr       */
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
	while (line[to_supress])
	{
		cpy[i] = line[to_supress];
		i++;
		to_supress++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	*parse_RGB(char *line)
{
	char	*cpy;
	char	**split;
	int		*tmp;
	int		i;

	tmp = malloc(sizeof(int) * 4);
	cpy = supp_space(line, 2);
	if (!cpy)
		return (NULL);
	split = ft_split(cpy, ',');
	i = 0;
	while (i < 3)
	{
		tmp[i] = ft_atoi(split[i]);
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (tmp);
}

int	check_RGB(t_game *game, char *line, int nb)
{
	if (nb == 4)
	{
		if (compare_str("F", line, 1) == 1)
			game->texture.F = parse_RGB(line);
		return (1);	
	}
	else if (nb == 5)
	{
		if (compare_str("C", line, 1) == 1)
			game->texture.C = parse_RGB(line);
		return (1);
	}
	else
		return (0);
}

int check_texture(t_game *game, char *line, int nb)
{
	if (nb == 0)
	{
		if (compare_str("NO", line, 2))
			return (game->texture.NO = supp_space(line, 2), 1);
	}
	else if (nb == 1)
	{
		if (compare_str("SO", line, 2) == 1)
			return (game->texture.SO = supp_space(line, 2), 1);	
	}
	else if (nb == 2)
	{
		if (compare_str("WE", line, 2) == 1)
			return (game->texture.WE = supp_space(line, 2), 1);	
	}
	else if (nb == 3)
	{
		if (compare_str("EA", line, 2) == 1)
			return (game->texture.EA = supp_space(line, 2), 1);	
	}
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
			if (nb <= 3 && check_texture(game, line, nb) == 1)
				nb++;
			else if (nb <= 5 && check_RGB(game, line, nb) == 1)
				nb++;
		}
		free(line);
		line = get_next_line(fd);
		game->count++;
	}
	free(line);
}
