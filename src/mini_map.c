/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:56 by luhumber          #+#    #+#             */
/*   Updated: 2023/09/05 14:44:04 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mini_line(t_game *game, int i, int j)
{
	if (game->tab_map[i][j] == '0')
		draw_square(game, game->height, game->lenght, 0x808080);
	else if (game->tab_map[i][j] == '1')
		draw_square(game, game->height, game->lenght, 0xB03030);
	draw_circle(game, game->player.height, game->player.lenght, game->player.color);
	game->lenght += 16;
}

void	mini_map(t_game *game)
{
	int	i;
	int	j;

	game->height = 0;
	i = game->player.y - 5;
	if (i < 0)
		i = 0;
	while (game->tab_map[i] && game->height <= 160)
	{
		game->lenght = 0;
		j = game->player.x - 5;
		if (j < 0)
			j = 0;
		while (game->tab_map[i][j] != '\n'
			&& game->tab_map[i][j] != '\0' && game->lenght <= 160)
			mini_line(game, i, j++);
		i++;
		game->height += 16;
	}
}
