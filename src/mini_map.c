/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:56 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/09 11:23:13 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	throw_ray(t_game *game, double x_start, double y_start, double angle)
{
	double	t;

	t = 0;
	
	double x = x_start + t * game->cos_angle;
    double y = y_start + t * game->sin_angle;
	while (game->tab_map[(int) y / 16 ][(int) x / 16] && game->tab_map[(int) y / 16 ][(int) x / 16] != '1')
	{
		if (game->tab_map[(int) (y_start / 16) ][(int) (x_start / 16)] == '1')
			break;
		t += 1;
		x = x_start + t * cos(angle);
		y = y_start + t * sin(angle);
		my_mlx_pixel_put(game->data, x, y, 0x000080);
	}
	// printf("%f, %f \n", game->ray->lengthray_X, game->ray->lengthray_Y);
}

void	mini_line(t_game *game, int i, int j)
{
	if (game->tab_map[i][j] == '0')
		draw_square(game, game->height, game->lenght, game->tex.c);
	else if (game->tab_map[i][j] == '1')
		draw_square(game, game->height, game->lenght, game->tex.f);
	draw_circle
		(game, game->player.height, game->player.lenght, game->player.color);
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
