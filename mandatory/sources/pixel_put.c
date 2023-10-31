/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:55:22 by chsiffre          #+#    #+#             */
/*   Updated: 2023/10/31 16:13:27 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	my_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + ((int)y * data->len + (int)x * (data->bpr / 8));
	if (!(x >= 0 && x <= 127) || !(y >= 0 && y <= 127))
	{
		return (*(uint32_t *)(data->addr + (127 * data->len + 127 * \
			(data->bpr / 8))));
	}
	return (*(uint32_t *)dst);
}

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	char	*dst;

	if (x < WIN_W && y < WIN_H && x > 0 && y > 0)
	{
		dst = data->addr + ((int)y * data->len + (int)x * (data->bpr / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_wall(t_game *game, int *y, int y_max, int color)
{
	while (*y <= y_max)
	{
		if (game->ray->horizontal == true)
			color = get_text_ns(game, y, game->ray->wall_size);
		else if (game->ray->horizontal == false)
			color = get_text_we(game, y, game->ray->wall_size);
		my_mlx_pixel_put(game->data, game->ray->x, *y, color);
		(*y)++;
	}
}

void	draw_ceilling_floor(t_game *game, int *y, int y_max, int color)
{
	while (*y < y_max)
	{
		my_mlx_pixel_put(game->data, game->ray->x, *y, color);
		(*y)++;
	}
}
