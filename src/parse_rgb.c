/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:38:21 by luhumber          #+#    #+#             */
/*   Updated: 2023/09/28 13:38:06 by luhumber         ###   ########.fr       */
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

int	to_hexa(int nb)
{
	int	hexa;
	int	base;
	int tmp;

	base = 1;
	hexa = 0;
	while (nb > 0)
	{
		tmp = nb % 16;
		hexa = hexa + tmp * base;
		nb = nb / 16;
		base = base * 10;
	}
	return (hexa);
}

int	*allocate_rgb(t_game *game, char *line)
{
	char	*cpy;
	char	**split;
	int		*tmp;
	int		i;

	tmp = malloc(sizeof(int) * 4);
	cpy = supp_space(line, 2);
	if (!cpy)
		map_error(game, 0);
	split = ft_split(cpy, ',');
	i = 0;
	while (i < 3)
	{
		parse_rgb(game, split[i]);
		tmp[i] = ft_atoi(split[i]);
		if (tmp[i] > 255 || tmp[i] < 0)
			map_error(game, 0);
		printf("KO = %d\n", tmp[i]);
		tmp[i] = to_hexa(tmp[i]);
		printf("OK = %x\n", tmp[i]);
		i++;
	}
	if (split[i])
		map_error(game, 0);
	tmp[i] = '\0';
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (tmp);
}
