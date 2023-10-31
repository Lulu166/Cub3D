/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:43:31 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/31 16:23:32 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	mouse_click(int button, int x, int y, t_game *game)
{
	if (button == 1)
	{
		game->player.click_right = 0;
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

int	can_turn(t_game *game)
{
	if (game->player.rot_left == 1)
	{
		game->angle += M_PI / 24;
		if (game->angle > 2 * M_PI)
			game->angle = 0;
	}
	if (game->player.rot_right == 1)
	{
		game->angle -= M_PI / 24;
		if (game->angle < 0)
			game->angle = 2 * M_PI;
	}
	return (0);
}

int	can_mouse(t_game *game)
{
	if (game->player.click_right == 0)
	{
		if (game->player.mouse_left == 1)
		{
			game->angle += M_PI / 48;
			if (game->angle > 2 * M_PI)
				game->angle = 0;
			game->player.mouse_left = 0;
			mlx_mouse_move
				(game->screen.mlx, game->screen.win, WIN_W / 2, WIN_H / 2);
		}
		else if (game->player.mouse_right == 1)
		{
			game->angle -= M_PI / 48;
			if (game->angle < 0)
				game->angle = 2 * M_PI;
			game->player.mouse_right = 0;
			mlx_mouse_move
				(game->screen.mlx, game->screen.win, WIN_W / 2, WIN_H / 2);
		}
	}
	return (0);
}
