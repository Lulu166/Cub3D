/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:05:41 by luhumber          #+#    #+#             */
/*   Updated: 2023/08/20 17:39:55 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_window(t_game *game)
{
    mlx_destroy_window(game->screen.mlx, game->screen.img);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	//printf("OK = %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(game->screen.mlx, game->screen.img);
		exit(0);
	}
	return (0);
}

void    window_init(t_game *game)
{
    game->screen.mlx = mlx_init();
	game->screen.img = mlx_new_window(game->screen.mlx, 1920, 1080, "TEST");
    mlx_hook(game->screen.img, 17, 0L, close_window, game);
	mlx_hook(game->screen.img, 2, 1L << 0, key_press, game);
	mlx_loop(game->screen.mlx);
}