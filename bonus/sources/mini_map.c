/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:56 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/31 16:23:01 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	draw_circle(t_game *game, int y, int x, int color)
{
	int		i;
	int		j;
	float	dst;

	i = 0;
	while (i <= 32)
	{
		j = 0;
		while (j <= 32)
		{
			dst = sqrt(pow((i - 10), 2) + pow((j - 10), 2));
			if (dst < 5)
				my_mlx_pixel_put(game->data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_square(t_game *game, int height, int len, int color)
{
	int	pix_h;
	int	pix_l;
	int	i;
	int	j;

	i = 0;
	pix_h = height;
	pix_l = len;
	while (i < 32)
	{
		j = 0;
		pix_l = len;
		while (j < 32)
		{
			my_mlx_pixel_put(game->data, pix_l, pix_h, color);
			pix_l++;
			j++;
		}
		pix_h++;
		i++;
	}
}

void	mini_line(t_game *game, int i, int j)
{
	if (game->tab_map[i][j] == '0')
		draw_square(game, game->height, game->lenght, 0x808080);
	else if (game->tab_map[i][j] == '1')
		draw_square(game, game->height, game->lenght, 0xB03030);
	draw_circle
	(game, game->player.pos_y - 3, game->player.pos_x - 3, game->player.color);
	game->lenght += 32;
}

void	mini_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->height = 0;
	while (game->tab_map[i] && game->height <= WIN_H)
	{
		game->lenght = 0;
		j = 0;
		while (game->tab_map[i][j] && game->lenght <= WIN_W)
			mini_line(game, i, j++);
		i++;
		game->height += 32;
	}
}
