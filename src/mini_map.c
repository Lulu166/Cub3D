/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:56 by luhumber          #+#    #+#             */
/*   Updated: 2023/08/27 15:13:21 by luhumber         ###   ########.fr       */
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

void	mini_line(t_game *game, int i, int j, int height, int *lenght)
{
	if (game->tab_map[i][j] == '0')
		my_pixel_loop(game, height, *lenght, 0x000000FF);
	else if (game->tab_map[i][j] == '1')
		my_pixel_loop(game, height, *lenght, 0xFF0000);
	if (j == game->player.x && i == game->player.y)
		my_pixel_loop(game, height, *lenght, game->player.color);
	*lenght += 32;
}

void	mini_map(t_game *game)
{
	int	i;
	int	j;
	int	height;
	int	lenght;
	int	count_h;
	int	count_l;

	i = game->player.y - 4;
	if (i < 0)
		i = 0;
	height = 0;
	count_h = -1;
	while (game->tab_map[i] && ++count_h <= 8)
	{
		lenght = 0;
		count_l = -1;
		j = game->player.x - 4;
		if (j < 0)
			j = 0;
		while (game->tab_map[i][j] != '\n' && game->tab_map[i][j] != '\0' && ++count_l <= 8)
			mini_line(game, i, j++, height, &lenght);
		i++;
		height += 32;
	}
}