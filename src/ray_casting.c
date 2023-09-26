/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:06:32 by chsiffre          #+#    #+#             */
/*   Updated: 2023/09/26 11:21:46 by chsiffre         ###   ########.fr       */
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

int	ft_init_var(t_game *game, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double) WIN_W - 1;
	game->ray->raydirX = game->ray->dirX + game->ray->planeX * camera_x;
	game->ray->raydirY = game->ray->dirY + game->ray->planeY * camera_x;
	game->ray->mapX = game->ray->posX;
	game->ray->mapY = game->ray->posY;
	game->ray->deltaX = 1 / game->ray->raydirX;
	game->ray->deltaY = 1 / game->ray->raydirY;
	// game->ray->deltaX = sqrt(1 + (game->ray->raydirY * game->ray->raydirY) / (game->ray->raydirX * game->ray->raydirX));
	// game->ray->deltaY = sqrt(1 + (game->ray->raydirX * game->ray->raydirX) / (game->ray->raydirY * game->ray->raydirY));
	return (0);
}

void    ray_casting(t_game *game)
{
	int		x;
	int		i;
	int		color;
	int		line_height;
	double	wall_x;

	color = 0xB03030;
	x = 0;
	wall_x = 0;
	while (x++ < WIN_W)
	{
		ft_init_var(game, x);
		// ft_init_lenghtray();
		if (game->ray->raydirX < 0)
		{
			game->ray->stepX = -1;
			game->ray->lengthray_X = (game->ray->posX - game->ray->mapX) * game->ray->deltaX;
		}
		else
		{
			game->ray->stepX = 1;
			game->ray->lengthray_X = (game->ray->mapX + 1.0 - game->ray->posX) * game->ray->deltaX;
		}
		if (game->ray->raydirY < 0)
		{
			game->ray->stepY = -1;
			game->ray->lengthray_Y = (game->ray->posY - game->ray->mapY) * game->ray->deltaY;
		}
		else
		{
			game->ray->stepY = 1;
			game->ray->lengthray_Y = (game->ray->mapY + 1.0 - game->ray->posY) * game->ray->deltaY;
		}
		while (game->ray->hit == 0)
		{
			if (game->ray->lengthray_X < game->ray->lengthray_Y)
			{
				game->ray->lengthray_X += game->ray->deltaX;
				game->ray->mapX += game->ray->stepX;
				game->ray->side = 0;
			}
			else
			{
				game->ray->lengthray_Y += game->ray->deltaY;
				game->ray->mapY += game->ray->stepY;
				game->ray->side = 1;
				// printf("34\n");
			}
			if (game->tab_map[game->ray->mapX][game->ray->mapY] > '0')
				game->ray->hit = 1;
			// printf("5\n");
		}
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
		line_height = (int)(WIN_H / game->ray->perpWallDist);
		game->ray->DrawStart = -line_height / 2 + WIN_H / 2;
		if (game->ray->DrawStart < 0)
			game->ray->DrawStart = 0;
		game->ray->DrawEnd = line_height / 2 + WIN_H / 2;
		if (game->ray->DrawEnd >= WIN_H)
			game->ray->DrawEnd = WIN_H - 1;
		if (game->ray->side == 0 && wall_x)
			wall_x = game->ray->posY + game->ray->perpWallDist * game->ray->raydirY;
		else
			wall_x = game->ray->posX + game->ray->perpWallDist * game->ray->raydirX;
		i = game->ray->DrawStart;
		while (i < WIN_H)
		{
			if (game->ray->side == 1)
				color = (color >> 1) & 8355711;
			my_mlx_pixel_put(game->data, x, i, 0xB03030);
			i++;
		}
	}
}
