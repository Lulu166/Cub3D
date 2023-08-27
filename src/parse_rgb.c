/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:38:21 by luhumber          #+#    #+#             */
/*   Updated: 2023/08/27 19:25:59 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_RGB(t_game *game, char *split)
{
	int		i;
	
	i = -1;
	if (split == NULL || split[0] == '\n')
		map_error(game, 0);
	while (split[++i] != '\n' && split[i] != '\0')
		if (ft_isdigit(split[i]) == 0)
			map_error(game, 0);
}

int	*allocate_RGB(t_game *game, char *line)
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
		parse_RGB(game, split[i]);
		tmp[i] = ft_atoi(split[i]);
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
