/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:38:21 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/31 16:11:15 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	parse_rgb(t_game *game, char *split, int *tmp)
{
	int		i;

	i = -1;
	if (split == NULL || split[0] == '\n')
	{
		free(tmp);
		free(game->line);
		free_tab(game->split_line);
		return (-1);
	}
	while (split[++i] != '\n' && split[i] != '\0')
	{
		if (ft_isdigit(split[i]) == 0)
		{
			free(tmp);
			free(game->line);
			free_tab(game->split_line);
			return (-1);
		}
	}
	return (0);
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
		if (parse_rgb(game, split[i], tmp) == -1)
		{
			free_tab(split);
			map_error(game, 0, 0, 3);
		}
		tmp[i] = ft_atoi(split[i]);
		if (tmp[i] > 255 || tmp[i] < 0)
		{
			free(tmp);
			free(game->line);
			free_tab(split);
			free_tab(game->split_line);
			map_error(game, 0, 0, 3);
		}
	}
	if (split[i])
		map_error(game, 0, 0, 3);
	hexa = rgb_to_hexa(tmp);
	return (hexa);
}

void	rgb_error(t_game *game, int *tmp)
{
	free(game->line);
	free(tmp);
	free_tab(game->split_line);
	map_error(game, 0, 0, 3);
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
		rgb_error(game, tmp);
	split = ft_split(cpy, ',');
	free(cpy);
	if (split == NULL)
		rgb_error(game, tmp);
	hexa = split_to_hexa(game, hexa, split, tmp);
	free_tab(split);
	return (hexa);
}
