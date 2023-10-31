/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:17:29 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/31 16:17:31 by luhumber         ###   ########.fr       */
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

int	convert_value(int *tab)
{
	int	i;
	int	res;

	i = 0;
	while (i < 3)
		res = (res << 8) | tab[i++];
	return (res);
}

int	to_hexa(int nb)
{
	int	hexa;
	int	base;
	int	tmp;

	base = 1;
	hexa = 0;
	while (nb > 0)
	{
		tmp = nb % 32;
		hexa = hexa + tmp * base;
		nb = nb / 32;
		base = base * 32;
	}
	return (hexa);
}
