/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:08:26 by luhumber          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/12 11:03:23 by chsiffre         ###   ########.fr       */
=======
/*   Updated: 2023/10/11 17:18:42 by luhumber         ###   ########.fr       */
>>>>>>> 5cc1f5bf185a595cb2ef89ef4d9c537f6c797178
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	can_move(t_game *g)
{
	if (g->player.top == 1)
	{
		if (g->tab_map[(((int)g->player.posy) >> 4)][(((int) g->player.posx - 5) >> 4) + 1] != '1')
		{
			g->player.posx += cosf(g->angle) * 7;
			g->player.posy += sinf(g->angle) * 7;
		}
	}
	if (g->player.down == 1)
	{
		g->player.posx -= cosf(g->angle) * 7;
		g->player.posy -= sinf(g->angle) * 7;
	}
	if (g->player.left == 1)
	{
		g->player.posx += sinf(g->angle) * 7;
		g->player.posy -= cosf(g->angle) * 7;
	}
	if (g->player.right == 1)
	{

		g->player.posx -= (sinf(g->angle)) * 7;
		g->player.posy += (cosf(g->angle)) * 7;
	}
	return (0);
}

int	can_turn(t_game *game)
{
	if (game->player.rotLeft == 1)
	{
		game->angle -= M_PI / 24;
		if (game->angle < 0)
			game->angle = 2 * M_PI;
		//game->player.rotLeft = 0;

	}
	if (game->player.rotRight == 1)
	{
		game->angle += M_PI / 24;
		if (game->angle > 2 * M_PI)
			game->angle = 0;
		//game->player.rotRight = 0;
	}
	return (0);
}
