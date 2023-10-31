/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:36:12 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/31 16:23:32 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	init_player(t_game *game, int i, int j)
{
	if (game->tab_map[i][j] == 'N')
		game->player.orientation = 'N';
	else if (game->tab_map[i][j] == 'S')
		game->player.orientation = 'S';
	else if (game->tab_map[i][j] == 'E')
		game->player.orientation = 'E';
	else if (game->tab_map[i][j] == 'W')
		game->player.orientation = 'W';
	game->player.color = 0xFFD700;
	game->player.nb_p++;
	game->player.x = j;
	game->player.y = i;
	game->player.pos_y = game->player.y * 32;
	game->player.pos_x = game->player.x * 32;
	game->player.top = 0;
	game->player.right = 0;
	game->player.down = 0;
	game->player.left = 0;
	game->player.mouse_left = 0;
	game->player.mouse_right = 0;
	game->player.click_left = 0;
	game->player.click_right = 0;
	game->player.rot_left = 0;
	game->player.rot_right = 0;
	game->tab_map[i][j] = '0';
}

int	player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player.nb_p = 0;
	while (game->tab_map[i])
	{
		j = 0;
		while (game->tab_map[i][j])
		{
			if (is_player(game, i, j) == 1)
				init_player(game, i, j);
			j++;
		}
		i++;
	}
	if (game->player.nb_p != 1)
		return (0);
	return (1);
}
