/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:06:32 by chsiffre          #+#    #+#             */
/*   Updated: 2023/08/30 15:12:08 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

void    ray_casting(t_game *game)
{
    int x;
    int mapX;
    int mapY;

    mapX = 0;
    mapY = 0;
    x = 0;
    while (x++ < WIN_W)
    {
        mapX = game->ray->posX;
        mapY = game->ray->posY;
        game->ray->cameraX = 2 * x / WIN_W - 1;
        game->ray->raydirX = game->ray->dirX + game->ray->planeX * game->ray->cameraX;
        game->ray->raydirY = game->ray->dirY + game->ray->planeY * game->ray->cameraX;
        game->ray->deltaX = abs(1 / game->ray->dirX);
        game->ray->deltaY = abs(1 / game->ray->dirX);
        if (game->ray->raydirX < 0)
        {
            game->ray->stepX = -1;
            game->ray->lengthray_X = (game->ray->posX - mapX) * game->ray->deltaX;
        }
        else
        {
            game->ray->stepX = 1;
            game->ray->lengthray_X = (mapX + 1 - game->ray->posX) * game->ray->deltaX;
        }
        if (game->ray->raydirY < 0)
        {
            game->ray->stepY = -1;
            game->ray->lengthray_Y = (game->ray->posY - mapY) * game->ray->deltaY;
            
        }
        else
        {
            game->ray->stepY = 1;
            game->ray->lengthray_Y = (mapY + 1 - game->ray->posY) * game->ray->deltaY;
        }
        while (game->ray->hit == 0)
        {
            if (game->ray->lengthray_X < game->ray->lengthray_Y)
            {
                game->ray->lengthray_X += game->ray->deltaX;
                mapX += game->ray->stepX;
                game->ray->side = 0;
            }
            else
            {
                game->ray->lengthray_Y += game->ray->deltaY;
                mapY += game->ray->stepY;
                game->ray->side = 1;
            }
            if (game->tab_map[game->ray->mapX][game->ray->mapY] == 1)
                game->ray->hit = 1;
        }
    }
}