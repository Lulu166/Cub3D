/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:08:26 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/25 17:12:08 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"


void move_up(t_game *g)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = sinf(g->angle);
	added_value_x = cosf(g->angle);
	map_y = g->player.posy - added_value_y;
	map_x = g->player.posx + added_value_x;
	if (g->tab_map[(int)(((map_y) / 16 + 1))][(int)(((map_x) / 16))] != '1' && \
		g->tab_map[(int)(((map_y) / 16))][(int)(((map_x) / 16))] != '1')
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

	added_value_y = sinf(g->angle);
	added_value_x = cosf(g->angle);
	map_y = g->player.posy + added_value_y;
	map_x = g->player.posx - added_value_x;
	if (g->tab_map[(int)(((map_y) / 16 + 1))][(int)(((map_x) / 16))] != '1' && \
		g->tab_map[(int)(((map_y) / 16))][(int)(((map_x) / 16))] != '1')
	{
		g->player.posx -= added_value_x;
		g->player.posy += added_value_y;
	}
	//printf("y = %f, x = %f", map_y / 16, map_x / 16);
	// else
	// 	g->player.posx -= added_value_x;
}

void	move_left(t_game *g)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = sinf(g->angle - (M_PI / 2));
	added_value_x = cosf(g->angle + (M_PI / 2));
	map_y = g->player.posy + added_value_y;
	map_x = g->player.posx + added_value_x;
	printf("y = %f,  x = %f\n", g->player.posy / 16, g->player.posx / 16);
	if (g->tab_map[(int)(((map_y) / 16 + 1))][(int)(((map_x) / 16))] != '1' && \
		g->tab_map[(int)(((map_y) / 16))][(int)(((map_x) / 16))] != '1')
	{
		g->player.posx += added_value_x;
		g->player.posy += added_value_y;
	}

	// else
	// 	g->player.posx += added_value_x;
}

void	move_right(t_game *g)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = sinf(g->angle + (M_PI / 2));
	added_value_x = cosf(g->angle - (M_PI / 2));
	map_y = g->player.posy + added_value_y;
	map_x = g->player.posx + added_value_x;
	if (g->tab_map[(int)(((map_y) / 16 + 1.5))][(int)(((map_x) / 16))] != '1' && \
		g->tab_map[(int)(((map_y) / 16))][(int)(((map_x) / 16))] != '1')
	{
		g->player.posx += added_value_x;
		g->player.posy += added_value_y;
	}
	//printf("y = %f, x = %f", map_y / 16, map_x / 16);
	// else
	// 	g->player.posx += added_value_x;
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
	//printf("pos y = %f , pos x = %f \n", g->player.posy / 16, g->player.posx / 16);
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
