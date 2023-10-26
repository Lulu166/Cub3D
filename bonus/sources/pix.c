/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:09:44 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/25 16:23:10 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	char	*dst;

	if (x < WIN_W && y < WIN_H && x > 0 && y > 0)
	{
		dst = data->addr + ((int)y * data->len + (int)x * (data->bpr / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_circle(t_game *game, int y, int x, int color)
{
	int		i;
	int		j;
	float	dst;

	i = 0;
	while (i <= 16)
	{
		j = 0;
		while (j <= 16)
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