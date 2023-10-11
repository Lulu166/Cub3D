/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:50:55 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/11 16:26:12 by luhumber         ###   ########.fr       */
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
	{
		game->player.right = 1;
		//can_move(game);
	}
	else if (keycode == W_LOWER_KEY)
	{
		game->player.top = 1;
		//can_move(game);
	}
	else if (keycode == A_LOWER_KEY)
	{
		game->player.left = 1;
		//can_move(game);
	}
	else if (keycode == S_LOWER_KEY)
	{
		game->player.down = 1;
		//can_move(game);
	}
}

void	arrow_keys(int keycode, t_game *game)
{
	if (keycode == RIGHT_ARROW_KEY)
	{
		game->player.rotRight = 1;
		//can_turn(game);
	}
	else if (keycode == LEFT_ARROW_KEY)
	{
		game->player.rotLeft = 1;
		//can_turn(game);
	}
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
	(void)keycode;
	if (game->player.right == 1)
		game->player.right = 0;
	if (game->player.left == 1)
		game->player.left = 0;
	if (game->player.top == 1)
		game->player.top = 0;
	if (game->player.down == 1)
		game->player.down = 0;
	if (game->player.rotLeft == 1)
		game->player.rotLeft = 0;
	if (game->player.rotRight == 1)
		game->player.rotRight = 0;
	return (0);
}
