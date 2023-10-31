/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:08:26 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/31 15:23:53 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"


void move_up(t_game *g)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = sinf(g->angle) * 2;
	added_value_x = cosf(g->angle) * 2;
	map_y = g->player.posy - added_value_y;
	map_x = g->player.posx + added_value_x;
	if (g->tab_map[(int)(((map_y) / 32 + 0.25))][(int)(((map_x) / 32 - 0.25))] != '1' && \
		g->tab_map[(int)(((map_y) / 32 - 0.25))][(int)(((map_x) / 32 + 0.25))] != '1')
	{
		g->player.posx += added_value_x;
		g->player.posy -= added_value_y;
	}
}

void	move_down(t_game *g)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = sinf(g->angle) * 2;
	added_value_x = cosf(g->angle) * 2;
	map_y = g->player.posy + added_value_y;
	map_x = g->player.posx - added_value_x;
	if (g->tab_map[(int)(((map_y) / 32 + 0.25))][(int)(((map_x) / 32 - 0.25))] != '1' && \
		g->tab_map[(int)(((map_y) / 32 - 0.25))][(int)(((map_x) / 32 + 0.25))] != '1')
	{
		g->player.posx -= added_value_x;
		g->player.posy += added_value_y;
	}
}

void	move_left(t_game *g)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = sinf((g->angle - (M_PI / 2))) * 2;
	added_value_x = cosf((g->angle + (M_PI / 2))) * 2;
	map_y = g->player.posy + added_value_y;
	map_x = g->player.posx + added_value_x;
	if (g->tab_map[(int)(((map_y) / 32 + 0.3))][(int)(((map_x) / 32 + 0.3))] != '1' && \
		g->tab_map[(int)(((map_y) / 32 - 0.3))][(int)(((map_x) / 32 - 0.3))] != '1')
	{
		g->player.posx += added_value_x;
		g->player.posy += added_value_y;
	}
}

void	move_right(t_game *g)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = sinf(g->angle + (M_PI / 2)) * 2;
	added_value_x = cosf(g->angle - (M_PI / 2)) * 2;
	map_y = g->player.posy + added_value_y;
	map_x = g->player.posx + added_value_x;
	if (g->tab_map[(int)(((map_y) / 32 + 0.3))][(int)(((map_x) / 32 - 0.3))] != '1' && \
		g->tab_map[(int)(((map_y) / 32 - 0.3))][(int)(((map_x) / 32 + 0.3))] != '1')
	{
		g->player.posx += added_value_x;
		g->player.posy += added_value_y;
	}
}

int	can_move(t_game *g)
{
	if (g->player.top == 1)
		move_up(g);
	if (g->player.down == 1)
		move_down(g);
	if (g->player.left == 1)
		move_left(g);
	if (g->player.right == 1)
		move_right(g);
	return (0);
}

int	can_turn(t_game *game)
{
	if (game->player.rotLeft == 1)
	{
		game->angle += M_PI / 24;
		if (game->angle > 2 * M_PI)
			game->angle = 0;
	}
	if (game->player.rotRight == 1)
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
