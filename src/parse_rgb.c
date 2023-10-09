/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:38:21 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/09 11:43:09 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_rgb(t_game *game, char *split)
{
	int		i;

	i = -1;
	if (split == NULL || split[0] == '\n')
		map_error(game, 0);
	while (split[++i] != '\n' && split[i] != '\0')
		if (ft_isdigit(split[i]) == 0)
			map_error(game, 0);
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
		tmp = nb % 16;
		hexa = hexa + tmp * base;
		nb = nb / 16;
		base = base * 16;
	}
	return (hexa);
}

int	rgb_to_hexa(int *tmp)
{
	int		hexa;

	hexa = ((to_hexa(tmp[0]) << 16) | (to_hexa(tmp[1]) << 8) | to_hexa(tmp[2]));
	hexa = convert_value(tmp);
	free(tmp);
	return (hexa);
}

int	allocate_rgb(t_game *game, char *line)
{
	char	*cpy;
	char	**split;
	int		*tmp;
	int		i;
	int		hexa;

	tmp = malloc(sizeof(int) * 4);
	cpy = supp_space(line, 0);
	if (!cpy)
		map_error(game, 0);
	split = ft_split(cpy, ',');
	i = -1;
	while (++i < 3)
	{
		parse_rgb(game, split[i]);
		tmp[i] = ft_atoi(split[i]);
		if (tmp[i] > 255 || tmp[i] < 0)
			map_error(game, 0);
	}
	if (split[i])
		map_error(game, 0);
	hexa = rgb_to_hexa(tmp);
	free_tab(split);
	free(cpy);
	return (hexa);
}
