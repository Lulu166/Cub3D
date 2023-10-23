/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:50:55 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/12 17:12:52 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_window(t_game *game)
{
	free_for_end(game);
	exit (0);
}

void	movement_keys(int keycode, t_game *game)
{
	if (keycode == D_LOWER_KEY)
		game->player.right = 1;
	else if (keycode == W_LOWER_KEY)
		game->player.top = 1;
	else if (keycode == A_LOWER_KEY)
		game->player.left = 1;
	else if (keycode == S_LOWER_KEY)
		game->player.down = 1;
}

void	arrow_keys(int keycode, t_game *game)
{
	if (keycode == RIGHT_ARROW_KEY)
		game->player.rotRight = 1;
	else if (keycode == LEFT_ARROW_KEY)
		game->player.rotLeft = 1;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		free_for_end(game);
		exit(0);
	}
	else if (keycode == 109)
	{
		if (game->mini_map == 0)
			game->mini_map = 1;
		else if (game->mini_map == 1)
			game->mini_map = 0;
	}
	movement_keys(keycode, game);
	arrow_keys(keycode, game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == D_LOWER_KEY)
		game->player.right = 0;
	if (keycode == A_LOWER_KEY)
		game->player.left = 0;
	if (keycode == W_LOWER_KEY)
		game->player.top = 0;
	if (keycode == S_LOWER_KEY)
		game->player.down = 0;
	if (keycode == LEFT_ARROW_KEY)
		game->player.rotLeft = 0;
	if (keycode == RIGHT_ARROW_KEY)
		game->player.rotRight = 0;
	return (0);
}

int	mouse_click(int button,int x, int y, t_game *game)
{
	if (button == 1)
	{
		game->player.click_right = 0;
		mlx_mouse_hide(game->screen.mlx, game->screen.win);
		mlx_mouse_move
			(game->screen.mlx, game->screen.win, WIN_W / 2, WIN_H / 2);
	}
	else if (button == 3)
	{
		game->player.click_right = 1;
		mlx_mouse_show(game->screen.mlx, game->screen.win);
	}
	(void)x;
	(void)y;
	return (0);
}

int	mouse_hook(int x, int y, t_game *game)
{
	(void)y;
	if (x > WIN_W / 2)
		game->player.mouse_right = 1;
	else if (x < WIN_W / 2)
		game->player.mouse_left = 1;
	return (0);
}
