/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:38:21 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/18 11:18:25 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_rgb(t_game *game, char *split)
{
	int		i;

	i = -1;
	if (split == NULL || split[0] == '\n')
		map_error(game, 0, 0, 3);
	while (split[++i] != '\n' && split[i] != '\0')
		if (ft_isdigit(split[i]) == 0)
			map_error(game, 0, 0, 3);
}

int	rgb_to_hexa(int *tmp)
{
	int		hexa;

	hexa = ((to_hexa(tmp[0]) << 16) | (to_hexa(tmp[1]) << 8) | to_hexa(tmp[2]));
	hexa = convert_value(tmp);
	free(tmp);
	return (hexa);
}

int	split_to_hexa(t_game *game, int hexa, char **split, int *tmp)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		parse_rgb(game, split[i]);
		tmp[i] = ft_atoi(split[i]);
		if (tmp[i] > 255 || tmp[i] < 0)
			map_error(game, 0, 0, 3);
	}
	if (split[i])
		map_error(game, 0, 0, 3);
	hexa = rgb_to_hexa(tmp);
	return (hexa);
}

int	allocate_rgb(t_game *game, char *line)
{
	char	*cpy;
	char	**split;
	int		*tmp;
	int		hexa;

	hexa = -1;
	tmp = malloc(sizeof(int) * 4);
	if (!tmp)
		map_error(game, 0, 0, 2);
	cpy = supp_space(line, 0);
	if (!cpy)
	{
		free(line);
		close(game->fd);
		map_error(game, 0, 0, 3);
	}
	split = ft_split(cpy, ',');
	hexa = split_to_hexa(game, hexa, split, tmp);
	free_tab(split);
	free(cpy);
	return (hexa);
}
