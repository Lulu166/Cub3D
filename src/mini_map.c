/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:56 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/11 13:44:47 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	throw_ray(t_game *g, double x_start, double y_start, double angle)
{
	double	t;
	double	dist;

	dist = 0;
	t = 0;
	g->ray->dirX = x_start + t * g->cos_angle;
	g->ray->dirY = y_start + t * g->sin_angle;
	while (g->tab_map[(int)(g->ray->dirY) / 16][(int) g->ray->dirX / 16] && g->tab_map[(int) g->ray->dirY / 16 ][(int) g->ray->dirX / 16] != '1')
	{
		if (g->tab_map[(int)(y_start / 16)][(int)(x_start / 16)] == '1')
			break ;
		t += 1;
		g->ray->dirX = x_start + t * cos(angle) / 10;
		g->ray->dirY = y_start + t * sin(angle) / 10;
		dist += 0.20;
		my_mlx_pixel_put(g->data, g->ray->dirX, g->ray->dirY, 0x000080);
	}
	// printf(" x = %f, y = %f", g->ray->dirX / 16, g->ray->dirY / 16);
	return (dist);
}

void	mini_line(t_game *game, int i, int j)
{
	if (game->tab_map[i][j] == '0')
		draw_square(game, game->height, game->lenght, game->tex.c);
	else if (game->tab_map[i][j] == '1')
		draw_square(game, game->height, game->lenght, game->tex.f);
	// printf("x= %f, y = %f\n", game->player.posx / 16, game->player.posy / 16);
	draw_circle
		(game, game->player.posy, game->player.posx, game->player.color);
	game->lenght += 16;
}

void	mini_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->height = 0;
	while (game->tab_map[i])
	{
		game->lenght = 0;
		j = 0;
		while (game->tab_map[i][j])
			mini_line(game, i, j++);
		i++;
		game->height += 16;
	}
}
