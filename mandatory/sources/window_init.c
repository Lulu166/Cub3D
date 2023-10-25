/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:05:41 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/25 16:23:10 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	hook_reload(t_game *game)
{
	can_move(game);
	can_turn(game);
	can_mouse(game);
	mlx_destroy_image(game->screen.mlx, game->data->img);
	game->data->img = mlx_new_image(game->screen.mlx, WIN_W, WIN_H);
	mlx_clear_window(game->screen.mlx, game->screen.win);
	draw_map(game);
	if (game->mini_map == 1)
		mini_map(game);
	mlx_put_image_to_window
		(game->screen.mlx, game->screen.win, game->data->img, 0, 0);
	return (0);
}

void	game_loop(t_game *game)
{
	mlx_hook(game->screen.win, 17, 0L, close_window, game);
	mlx_hook(game->screen.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->screen.win, 6, 1L << 6, mouse_hook, game);
	mlx_mouse_hook(game->screen.win, mouse_click, game);
	mlx_hook(game->screen.win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->screen.mlx, hook_reload, game);
	mlx_loop(game->screen.mlx);
}

void	window_init(t_game *game)
{
	game->data = (t_data *)malloc(sizeof(t_data));
	if (!game->data)
		map_error(game, 1, 0, 0);
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		map_error(game, 2, 0, 0);
	game->screen.mlx = mlx_init();
	if (!game->screen.mlx)
		map_error(game, 2, 0, 0);
	game->screen.win = mlx_new_window(game->screen.mlx, WIN_W, WIN_H, "Cub3D");
	if (!game->screen.win)
		map_error(game, 2, 1, 0);
	game->data->img = mlx_new_image(game->screen.mlx, WIN_W, WIN_H);
	if (!game->data->img)
		map_error(game, 2, 2, 4);
	game->data->addr = mlx_get_data_addr
		(game->data->img, &game->data->bpr,
			&game->data->len, &game->data->endian);
	if (!game->data->addr)
		map_error(game, 2, 3, 4);
	game_loop(game);
}
