/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:56 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/02 16:51:04 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float ft_calculate_lenghtray(t_game *game, double x_start, double y_start)
{
	double x;
	double y;

	double deltax = cos(game->angle);
	double deltay = sin(game->angle);
	
	x = x_start;
	y = y_start;
	
	while (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		if (game->tab_map[(int) (y / 16) ][(int)(x / 16) ] && game->tab_map[(int) (y / 16) ][(int) (x / 16) ] == '1')
		{
			return (sqrt(x - x_start) * (x - x_start) + (y - y_start) * (y - y_start));
		}
		x += deltax;
		y += deltay;
	}
	return (-1.0);
}

void	throw_ray(t_game *game, double x_start, double y_start)
{
	int		i;
	double	side_dist;

	i = 0;
	double x = x_start;
	double y = y_start;
	game->ray->deltaX = cos(game->angle);
	game->ray->deltaY = sin(game->angle);
	side_dist = ft_calculate_lenghtray(game, x, y);
	// side_dist = 100;
	printf("%f\n", side_dist);
	while (i < side_dist)
	{
		if (game->tab_map[(int) (y / 16) ][(int) (x / 16)] == '1')
			my_mlx_pixel_put(game->data, x + 10, y + 10, 0x000000);
		else
			my_mlx_pixel_put(game->data, x + 10, y + 10, 0x000080);
		x += game->ray->deltaX;
		y += game->ray->deltaY;
		printf(" x = %f,  y = %f\n", x , y);
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
