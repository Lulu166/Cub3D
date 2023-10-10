/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:05:41 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/10 15:36:38 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void draw_wall(t_game *game, int *y, int y_max, int color)
{
	while (*y <= y_max)
	{
		my_mlx_pixel_put(game->data, game->ray->x, *y, color);
		(*y)++;
	}
}

void draw_ceilling_floor(t_game *game, int *y, int y_max, int color)
{
	while (*y < y_max)
	{
		my_mlx_pixel_put(game->data, game->ray->x, *y, color);
		(*y)++;
	}
}

void	draw_all(t_game *game, double dist)
{
	int y;
	double wall_size;
	double half_size;
	
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
	int y;
	double dist;

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

int	hook_reload(t_game *game)
{
	mlx_destroy_image(game->screen.mlx, game->data->img);
	game->data->img = mlx_new_image(game->screen.mlx, WIN_H, WIN_W);
	mlx_clear_window(game->screen.mlx, game->screen.win);
	draw_map(game);
	if (game->mini_map == 1)
		mini_map(game);
	mlx_put_image_to_window
		(game->screen.mlx, game->screen.win, game->data->img, 0, 0);
	return (0);
}

void	window_init(t_game *game)
{
	game->data = (t_data *)malloc(sizeof(t_data));
	if (!game->data)
		map_error(game, 1);
	game->screen.mlx = mlx_init();
	if (!game->screen.mlx)
		map_error(game, 1);
	game->screen.win = mlx_new_window(game->screen.mlx, WIN_H, WIN_W, "Cub3D");
	game->data->img = mlx_new_image(game->screen.mlx, WIN_H, WIN_W);
	game->data->addr = mlx_get_data_addr
		(game->data->img, &game->data->bpr,
			&game->data->len, &game->data->endian);
	mlx_hook(game->screen.win, 17, 0L, close_window, game);
	mlx_hook(game->screen.win, 2, 1L << 0, key_press, game);
	mlx_loop_hook(game->screen.mlx, hook_reload, game);
	mlx_loop(game->screen.mlx);
}
