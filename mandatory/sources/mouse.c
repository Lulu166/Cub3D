/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:43:31 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/26 10:56:00 by luhumber         ###   ########.fr       */
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
