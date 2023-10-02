/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:56 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/02 11:35:32 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double ft_calculate_lenghtray(t_game *game, double x, double y)
{
	game->ray->mapX = 5 * x;
	game->ray->mapY = 5 * y;

	if (game->ray->raydirX < 0)
	{
		game->ray->stepX = -1;
		game->ray->lengthray_X = (x - game->ray->mapX) * game->ray->deltaX;
	}
	else
	{
		game->ray->stepX = 1;
		game->ray->lengthray_X = (game->ray->mapX + 1.0 - x) * game->ray->deltaX;
	}
	if (game->ray->raydirY < 0)
	{
		game->ray->stepY = -1;
		game->ray->lengthray_Y = (game->ray->posY - y) * game->ray->deltaY;
	}
	else
	{
		game->ray->stepY = 1;
		game->ray->lengthray_Y = (y + 1.0 - game->ray->posY) * game->ray->deltaY;
	}
	if (game->ray->lengthray_Y > game->ray->lengthray_X)
		return (game->ray->lengthray_Y);
	else
		return (game->ray->lengthray_X);
}

void	throw_ray(t_game *game, double x, double y)
{
	int		i;
	double	side_dist;

	side_dist = ft_calculate_lenghtray(game, x, y);
	i = 0;
	game->ray->deltaX = cos(game->angle);
	game->ray->deltaY = sin(game->angle);
	while (i < side_dist)
	{
		my_mlx_pixel_put(game->data, x + 10, y + 10, 0x00008B);
		x += game->ray->deltaX;
		y += game->ray->deltaY;
		i++;
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
	throw_ray(game, game->player.lenght, game->player.height);
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
