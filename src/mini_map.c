/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:56 by luhumber          #+#    #+#             */
/*   Updated: 2023/09/26 11:17:17 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	throw_ray(t_game *game, double x, double y)
{
	int	i;
	int longueur;

	longueur = 100;
	i = 0;

    double	deltaX = cos(game->angle);
    double	deltaY = sin(game->angle);

    while (i < longueur)
	{
        my_mlx_pixel_put(game->data, x + 10, y + 10, 0x00008B);
        x += deltaX;
        y += deltaY;
		i++;
    }
	printf("%f , %f \n", game->ray->lengthray_X, game->ray->lengthray_Y);
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
