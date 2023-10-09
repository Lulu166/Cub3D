/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:08:26 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/09 15:24:31 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	can_move(t_game *game)
{
	if (game->player.top == 1)
	{
		game->player.posx += cosf(game->angle) * 2;
		game->player.posy += sinf(game->angle) * 2;
		game->player.top = 0;
	}
	if (game->player.down == 1)
	{
		game->player.posx -= cosf(game->angle) * 2;
		game->player.posy -= sinf(game->angle) * 2;
		game->player.down = 0;

	}
	if (game->player.left == 1)
	{
		game->player.posx += sin(game->angle) * 2;
		game->player.posy -= cos(game->angle) * 2;
		game->player.left = 0;
	}
	if (game->player.right == 1)
	{

		game->player.posx -= (sinf(game->angle)) * 2;
		game->player.posy += (cosf(game->angle)) * 2;
		game->player.right = 0;
	}
	return (0);
}

int	can_turn(t_game *game)
{
	if (game->player.rotLeft == 1)
	{
		double oldDirX = game->ray->dirX;
      	game->ray->dirX = game->ray->dirX * cos(0.3) - game->ray->dirY * sin(0.3);
      	game->ray->dirY = oldDirX * sin(0.3) + game->ray->dirY * cos(0.3);
      	double oldPlaneX = game->ray->planeX;
      	game->ray->planeX = game->ray->planeX * cos(0.3) - game->ray->planeY * sin(0.3);
      	game->ray->planeY = oldPlaneX * sin(0.3) + game->ray->planeY * cos(0.3);
		game->player.rotLeft = 0;

		game->angle -= M_PI / 24;
		if (game->angle < 0)
			game->angle = 2 * M_PI;

	}
	if (game->player.rotRight == 1)
	{
		double oldDirX = game->ray->dirX;
      	game->ray->dirX = game->ray->dirX * cos(-0.3) - game->ray->dirY * sin(-0.3);
      	game->ray->dirY = oldDirX * sin(-0.3) + game->ray->dirY * cos(-0.3);
      	double oldPlaneX = game->ray->planeX;
      	game->ray->planeX = game->ray->planeX * cos(-0.3) - game->ray->planeY * sin(-0.3);
      	game->ray->planeY = oldPlaneX * sin(-0.3) + game->ray->planeY * cos(-0.3);
		game->player.rotRight = 0;

		game->angle += M_PI / 24;
		if (game->angle > 2 * M_PI)
			game->angle = 0;
	}
	return (0);
}
