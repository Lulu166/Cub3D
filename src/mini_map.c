/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:56 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/02 11:35:01 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int ft_calculate_lenghtray(t_game *game, double x, double y)
{
	// int side_dist;
	// (void) game;
	// // (void) x;
	// // (void) y;
	// side_dist = (165 - (int)x) * (165 - (int)x) + (165 - (int)y) * (165 - (int)y);
	// side_dist = sqrt(side_dist);

	// return (side_dist);
	game->ray->mapX = 1.5 *(int)x;
	game->ray->mapY = 1.5 *(int)y;
	//printf("%d , %d \n", game->ray->mapX, game->ray->mapY);
	
	if ((int)game->ray->deltaX == -1 && (int)game->ray->deltaY == 0)
	{
		printf("gauche\n");
		return ((int)x + 10);
	}
	if ((int)game->ray->deltaX == 0 && (int)game->ray->deltaY == -1)
	{
		printf("bas\n");
		return ((int)y + 10);
	}
	if ((int)game->ray->deltaX == 0 && (int)game->ray->deltaY == 1)
	{
		printf("haut\n");
		return (165 - ((int)y));
	}
	if ((int)game->ray->deltaX == 1 && (int)game->ray->deltaY == 0)
	{
		printf("droite\n");
		return (165 - ((int)x));
	}
	return (1000);
}

void	throw_ray(t_game *game, double x, double y)
{
	int	i;
	double side_dist;

	i = 0;
    game->ray->deltaX = cos(game->angle);
    game->ray->deltaY = sin(game->angle);
	side_dist = ft_calculate_lenghtray(game, x, y);
    while (i < 150)
	{
		// if (game->tab_map[(int)y / 16][(int)x / 16] == '0')
        my_mlx_pixel_put(game->data, x + 10, y + 10, 0xFFFFFF);
        x += game->ray->deltaX;
        y += game->ray->deltaY;
		i++;
    }
	// printf("%f , %f \n", game->ray->lengthray_X, game->ray->lengthray_Y);
}

void	mini_line(t_game *game, int i, int j)
{
	if (game->tab_map[i][j] == '0')
		draw_square(game, game->height, game->lenght, 0x808080);
	else if (game->tab_map[i][j] == '1')
		draw_square(game, game->height, game->lenght, 0xB03030);
	draw_circle(game, game->player.height, game->player.lenght, game->player.color);
	throw_ray(game,game->player.lenght, game->player.height);
	
	game->lenght += 16;
}

void	mini_map(t_game *game)
{
	int	i;
	int	j;

	game->height = 0;
	i = game->player.y - 5;
	if (i < 0)
		i = 0;
	while (game->tab_map[i] && game->height <= 160)
	{
		game->lenght = 0;
		j = game->player.x - 5;
		if (j < 0)
			j = 0;
		while (game->tab_map[i][j] != '\n'
			&& game->tab_map[i][j] != '\0' && game->lenght <= 160)
			mini_line(game, i, j++);
		i++;
		game->height += 16;
	}
}
