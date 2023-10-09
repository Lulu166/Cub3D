/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:05:41 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/09 13:58:08 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	hook_reload(t_game *game)
{
	mlx_destroy_image(game->screen.mlx, game->data->img);
	game->data->img = mlx_new_image(game->screen.mlx, WIN_H, WIN_W);
	mlx_clear_window(game->screen.mlx, game->screen.win);
	//draw_map(game);
	//ray_casting(game);
	if (game->mini_map == 1)
		mini_map(game);
	int x = 1;
	while (x < WIN_W)
	{
		// game->angle += M_PI / 120;
		game->shift = ((float) x / WIN_W) + 1;
		game->cos_angle = cos((game->shift * (M_PI / 3)) + game->angle);
        game->sin_angle = -sin((game->shift * (M_PI / 3) + game->angle));
        game->shift = (game->shift - 1.5) * (M_PI / 3);
		// printf("%f\n", game->angle);
		throw_ray(game, game->player.lenght + 10, game->player.height + 10, game->angle + game->shift);
		x++;
	}
	//ray_casting(game);
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
