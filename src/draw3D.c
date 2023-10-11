/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:46:17 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/11 16:29:46 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_wall(t_game *game, int *y, int y_max, int color)
{
	while (*y <= y_max)
	{
		my_mlx_pixel_put(game->data, game->ray->x, *y, color);
		(*y)++;
	}
}

void	draw_ceilling_floor(t_game *game, int *y, int y_max, int color)
{
	while (*y < y_max)
	{
		my_mlx_pixel_put(game->data, game->ray->x, *y, color);
		(*y)++;
	}
}

void	draw_all(t_game *game, double dist)
{
	int		y;
	double	wall_size;
	double	half_size;

	y = 0;
	if (dist == 0)
		dist = 0.2;
	wall_size = (1 / ((dist) * cos(game->shift))) * 35000;
	half_size = wall_size / 2;
	draw_ceilling_floor(game, &y, ((WIN_H / 2) - half_size), game->tex.c);
	draw_wall(game, &y, ((WIN_H / 2) + half_size), 0x79615C);
	draw_ceilling_floor(game, &y, WIN_H, game->tex.f);
}

void	draw_map(t_game *game)
{
	int		y;
	double	dist;

	y = 0;
	init_ray_struct(game);
	while (game->ray->x < WIN_W)
	{
		game->shift = ((float) game->ray->x / WIN_W) + 1;
		game->cos_angle = cosf((game->shift * (M_PI / 3)) + game->angle);
		game->sin_angle = -sinf((game->shift * (M_PI / 3) + game->angle));
		game->shift = (game->shift - 1.5) * (M_PI / 3);
		dist = throw_ray(game, game->player.posx + 10, game->player.posy + 10, game->angle + game->shift);
		draw_all(game, dist);
		game->ray->x++;
	}
}
