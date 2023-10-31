/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_pix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:15:02 by chsiffre          #+#    #+#             */
/*   Updated: 2023/10/31 13:43:26 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

static int	float_modulo(float nbr, int div);

int	get_text_ns(t_game *game, int x, int *y, long wall_size)
{
	int	x_pix_get;
	int	y_pix_get;
	int	color;

	color = 0;
	x_pix_get = ((float_modulo(game->data->collision[0], \
	16) * 256) / 16);
	y_pix_get = (((*y - ((WIN_H / 2) - (wall_size >> 1))) * 256) \
	/ (wall_size));
	if (game->sin_angle < 0)
	{
		color = my_pixel_get();
	}
	else if (game->sin_angle > 0)
	{
		x_pix_get = (256 - 1) - x_pix_get;
		color = my_pixel_get();
	}
	return (color);
}

int	get_text_we(t_game *game, int x, int *y, long wall_size)
{
	int	x_pix_get;
	int	y_pix_get;
	int	color;

	color = 0;
	x_pix_get = ((float_modulo(game->data->collision[1], \
	16) * 256) / 16);
	y_pix_get = (((*y - ((WIN_H / 2) - (wall_size >> 1))) * 256) \
	/ (wall_size));
	if (game->cos_angle < 0)
	{
		x_pix_get = (256 - 1) - x_pix_get;
		color = my_pixel_get();
	}
	else if (game->cos_angle > 0)
	{
		color = my_pixel_get();
	}
	return (color);
}

static int	float_modulo(float nbr, int div)
{
	int	i;

	i = nbr / div;
	nbr -= i * div;
	return (nbr);
}
