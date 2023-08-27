/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:05:41 by luhumber          #+#    #+#             */
/*   Updated: 2023/08/27 19:28:09 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_window(t_game *game)
{
    mlx_destroy_window(game->screen.mlx, game->screen.win);
	free_for_end(game);
	exit (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->screen.mlx, game->screen.win);
		free_for_end(game);
		exit(0);
	}
	else if (keycode == 100)
		can_move(game, game->player.x + 1, game->player.y);
	else if (keycode == 119)
		can_move(game, game->player.x, game->player.y - 1);
	else if (keycode == 97)
		can_move(game, game->player.x - 1, game->player.y);
	else if (keycode == 115)
		can_move(game, game->player.x, game->player.y + 1);
	return (0);
}

int	hook_reload(t_game *game)
{
	mlx_destroy_image(game->screen.mlx, game->data->img);
	game->data->img = mlx_new_image(game->screen.mlx, 1920, 1080);
	mlx_clear_window(game->screen.mlx, game->screen.win);
	mini_map(game);
	mlx_put_image_to_window(game->screen.mlx, game->screen.win, game->data->img, 0, 0);
	return (0);
}

void    window_init(t_game *game)
{
	game->data = (t_data *)malloc(sizeof(t_data));
	if (!game->data)
		map_error(game, 1);
    game->screen.mlx = mlx_init();
	game->screen.win = mlx_new_window(game->screen.mlx, 1920, 1080, "Cub3D");
    game->data->img = mlx_new_image(game->screen.mlx, 1920, 1080);
	game->data->addr = mlx_get_data_addr(game->data->img, &game->data->bpr, &game->data->len, &game->data->endian);
	mlx_hook(game->screen.win, 17, 0L, close_window, game);
	mlx_hook(game->screen.win, 2, 1L << 0, key_press, game);
	mlx_loop_hook(game->screen.mlx, hook_reload, game);
	mlx_loop(game->screen.mlx);
}
