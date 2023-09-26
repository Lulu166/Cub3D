/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:05:41 by luhumber          #+#    #+#             */
/*   Updated: 2023/09/22 17:41:41 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


// void	clear_image(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WIN_H)
// 	{
// 		j = 0;
// 		while (j < WIN_W)
// 		{
// 			game->tab_map[(int)i * WIN_W + (int)j] = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// }

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
	else if (keycode == D_LOWER_KEY)
	{
		game->player.right = 1;
		can_move(game);
	}
	else if (keycode == W_LOWER_KEY)
	{
		game->player.top = 1;
		can_move(game);
	}
	else if (keycode == A_LOWER_KEY)
	{
		game->player.left = 1;
		can_move(game);
	}
	else if (keycode == S_LOWER_KEY)
	{
		game->player.down = 1;
		can_move(game);
	}
	else if (keycode == RIGHT_ARROW_KEY)
	{
		game->player.rotRight = 1;
		can_turn(game);
	}
	else if (keycode == LEFT_ARROW_KEY)
	{
		game->player.rotLeft = 1;
		can_turn(game);
	}
	return (0);
}

int	hook_reload(t_game *game)
{
	mlx_destroy_image(game->screen.mlx, game->data->img);
	game->data->img = mlx_new_image(game->screen.mlx, WIN_H, WIN_W);
	mlx_clear_window(game->screen.mlx, game->screen.win);
	//draw_map(game);
	ray_casting(game);
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
