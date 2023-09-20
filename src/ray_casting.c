/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:06:32 by chsiffre          #+#    #+#             */
/*   Updated: 2023/09/18 10:34:58 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

// void	draw_window(t_game *game)
// {
// 	int	i;
// 	int	y;

// 	i = 0;
// 	y = 0;
// 	while( i < WIN_W)
// 	{
		
// 	}
// }

void    ray_casting(t_game *game)
{
	int x;
	int	i;
	int mapX;
	int mapY;
	int color;

	color = 0xB03030;
	mapX = 0;
	mapY = 0;
	x = 0;

	while (x++ < WIN_W)
	{
	// 	mapX = game->ray->posX;
	// 	mapY = game->ray->posY;
		game->ray->cameraX = 2 * x / (double) WIN_W - 1;
		game->ray->raydirX = game->ray->dirX + game->ray->planeX * game->ray->cameraX;
		game->ray->raydirY = game->ray->dirY + game->ray->planeY * game->ray->cameraX;
		game->ray->deltaX = sqrt(1 + (game->ray->raydirY * game->ray->raydirY) / (game->ray->raydirX * game->ray->raydirX));
		game->ray->deltaY = sqrt(1 + (game->ray->raydirX * game->ray->raydirX) / (game->ray->raydirY * game->ray->raydirY));
		
		// printf("deltaX : %f deltaY : %f\n",  game->ray->deltaX, game->ray->deltaY);
		if (game->ray->raydirX < 0)
		{
			game->ray->stepX = -1;
			game->ray->lengthray_X = (game->ray->posX - mapX) * game->ray->deltaX;
		}
		else
		{
			game->ray->stepX = 1;
			game->ray->lengthray_X = (mapX + 1.0 - game->ray->posX) * game->ray->deltaX;
		}
		if (game->ray->raydirY < 0)
		{
			game->ray->stepY = -1;
			game->ray->lengthray_Y = (game->ray->posY - mapY) * game->ray->deltaY;	
		}
		else
		{
			game->ray->stepY = 1;
			game->ray->lengthray_Y = (mapY + 1.0 - game->ray->posY) * game->ray->deltaY;
		}
		// printf("lenghtrayx : %f , lenghtrayY : %f deltaX : %f deltaY : %f\n", game->ray->lengthray_X, game->ray->lengthray_Y, game->ray->deltaX, game->ray->deltaY);
		while (game->ray->hit == 0)
		{
			if (game->ray->lengthray_X < game->ray->lengthray_Y)
			{
				game->ray->lengthray_X += game->ray->deltaX;
				mapX += game->ray->stepX;
				game->ray->side = 0;
				// printf("44\n");	
			}
			else
			{
				game->ray->lengthray_Y += game->ray->deltaY;
				mapY += game->ray->stepY;
				game->ray->side = 1;
				// printf("34\n");
			}
			if (game->tab_map[game->ray->mapX][game->ray->mapY] > '0')
				game->ray->hit = 1;
			// printf("5\n");
		}
		// printf("lenghtrayX : %f\n lenghtrayY : %f\n", game->ray->lengthray_X, game->ray->lengthray_Y);
		if (game->ray->side == 0)
		{
			// printf("1\n");
			game->ray->perpWallDist = (game->ray->lengthray_X - game->ray->deltaX);
		}
      	else
		{
			// printf("2\n");
			game->ray->perpWallDist = (game->ray->lengthray_Y - game->ray->deltaY);
		}
		// printf("lenghtrayX : %f\n lenghtrayY : %f", game->ray->lengthray_X, game->ray->lengthray_Y);
		// printf("perpWalldist : %f\n", game->ray->perpWallDist);
		int lineHeight = 0;
		lineHeight = (int) (WIN_H / game->ray->perpWallDist);
		// printf(" lineheight : %d\n", lineHeight);
		game->ray->DrawStart = -lineHeight / 2 +  WIN_H / 2;
		if (game->ray->DrawStart < 0)
			game->ray->DrawStart = 0;
		game->ray->DrawEnd = lineHeight / 2 + WIN_H / 2;
		if (game->ray->DrawEnd >= WIN_H)
			game->ray->DrawEnd = WIN_H - 1;
		i = game->ray->DrawStart;
		double	wallX = 0;
		if (game->ray->side == 0 && wallX)
			wallX = game->ray->posY + game->ray->perpWallDist * game->ray->raydirY;
		else
			wallX = game->ray->posX + game->ray->perpWallDist * game->ray->raydirX;
		// printf("start : %d\n end : %d\n", game->ray->DrawStart, gaaaaaaaaaaaaassddwwdddame->ray->DrawEnd);
		// exit(1);
		while (i < game->ray->DrawEnd)
		{
			if (game->ray->side == 1)
				color = (color >> 1) & 8355711;
			my_mlx_pixel_put(game->data, x, i, 0xB03030);
			i++;
		}
	}
}