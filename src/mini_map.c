/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:56 by luhumber          #+#    #+#             */
/*   Updated: 2023/08/30 12:05:58 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpr / 8));
	*(unsigned int *)dst = color;
}

void	my_pixel_loop(t_game *game, int height, int len, int color)
{
	int	pix_h;
	int	pix_l;
	int	i;
	int	j;

	i = 0;
	pix_h = height;
	pix_l = len;
	while (i < 16)
	{
		j = 0;
		pix_l = len;
		while (j < 16)
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
		my_pixel_loop(game, game->height, game->lenght, 0x808080);
	else if (game->tab_map[i][j] == '1')
		my_pixel_loop(game, game->height, game->lenght, 0xB03030);
	if (j == game->player.x && i == game->player.y)
		my_pixel_loop(game, game->height, game->lenght, game->player.color);
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
