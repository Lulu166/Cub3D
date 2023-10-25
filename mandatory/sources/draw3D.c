/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:46:17 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/25 16:23:10 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

static void	draw_v_coll(t_game *game, t_pointf *xy_v, float dist, int i);
static void	draw_h_coll(t_game *game, t_pointf *xy_h, float dist, int i);

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
	// (void) color;
	// (void) game;
	while (*y < y_max)
	{
		my_mlx_pixel_put(game->data, game->ray->x, *y, color);
		(*y)++;
	}
}

void	draw_all(t_game *game, float dist, float angle, int i)
{
	int		y;
	float	wall_size;
	float	half_size;

	y = 0;
	if (dist == 0)
		dist = 0.2;
	wall_size = 1 / (dist * cos(angle)) * 20000;
	half_size = wall_size / 2;
	game->ray->x = i;
	draw_ceilling_floor(game, &y, ((WIN_H >> 1) - half_size), game->tex.c);
	draw_wall(game, &y, ((WIN_H >> 1) + half_size), 0x79615C);
	draw_ceilling_floor(game, &y, WIN_H, game->tex.f);
}

void	draw_map(t_game *game)
{
	float	dist_h;
	float	dist_v;
	t_pointf	xy_v;
	t_pointf	xy_h;
	int			i;
	
	i = 1;
	init_ray_struct(game);
	game->ray->opposit = WIN_W / 2;
	game->ray->adjacent = game->ray->opposit / tan(M_PI / 6);
	game->ray->ray_angle = (M_PI / 6) + game->angle;
	while (i <= WIN_W)
	{
		init_ray(game, &xy_v, &xy_h);
		dist_h = check_horizontal(game, &xy_h);
		dist_v = check_vertical(game, &xy_v);
		if (dist_h <= dist_v)
			draw_h_coll(game, &xy_h, dist_h, i);
		else if (dist_h > dist_v)
			draw_v_coll(game, &xy_v, dist_v, i);
		i++;
		game->ray->opposit--;
		game->ray->ray_angle = atanf(game->ray->opposit / game->ray->adjacent) + game->angle;
	}
	// printf("dist h = %f\n, dist v = %f", dist_h, dist_v);
}
static void	draw_h_coll(t_game *game, t_pointf *xy_h, float dist, int i)
{
	game->collision[0] = xy_h->x;
	game->collision[1] = xy_h->y + 1;
	game->ray->horizontal = true;
	draw_all(game, dist, game->ray->ray_angle - game->angle, i);
}

static void	draw_v_coll(t_game *game, t_pointf *xy_v, float dist, int i)
{
	game->collision[0] = xy_v->x + 1;
	game->collision[1] = xy_v->y;
	game->ray->horizontal = false;
	draw_all(game, dist, game->ray->ray_angle - game->angle, i);
}
