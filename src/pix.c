/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:09:44 by luhumber          #+#    #+#             */
/*   Updated: 2023/09/05 11:02:58 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpr / 8));
	*(unsigned int *)dst = color;
}

void	draw_circle(t_game *game, int y, int x, int color)
{
	int		i;
	int		j;
	float	dst;

	i = 0;
	while (i <= 20)
	{
		j = 0;
		while (j <= 20)
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
