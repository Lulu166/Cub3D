/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_pix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:15:02 by chsiffre          #+#    #+#             */
/*   Updated: 2023/10/31 16:25:39 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

static float	float_modulo(float nbr, int div);

int	get_text_ns(t_game *game, int *y, long wall_size)
{
	int	x_pix_get;
	int	y_pix_get;
	int	color;

	color = 0;
	x_pix_get = ((float_modulo(game->collision[0], \
	32) * 128) / 32);
	y_pix_get = (((*y - ((WIN_H / 2) - (wall_size >> 1))) * 128) \
	/ (wall_size));
	if (game->sin_angle < 0)
	{
		color = my_pixel_get(&game->tex.no_img.data, x_pix_get, y_pix_get);
	}
	else if (game->sin_angle > 0)
	{
		x_pix_get = (128 - 1) - x_pix_get;
		color = my_pixel_get(&game->tex.so_img.data, x_pix_get, y_pix_get);
	}
	return (color);
}

int	get_text_we(t_game *game, int *y, long wall_size)
{
	int	x_pix_get;
	int	y_pix_get;
	int	color;

	color = 0;
	x_pix_get = ((float_modulo(game->collision[1], \
	32) * 128) / 32);
	y_pix_get = (((*y - ((WIN_H / 2) - (wall_size >> 1))) * 128) \
	/ (wall_size));
	if (game->cos_angle < 0)
	{
		x_pix_get = (128 - 1) - x_pix_get;
		color = my_pixel_get(&game->tex.we_img.data, x_pix_get, y_pix_get);
	}
	else if (game->cos_angle > 0)
	{
		color = my_pixel_get(&game->tex.ea_img.data, x_pix_get, y_pix_get);
	}
	return (color);
}

static float	float_modulo(float nbr, int div)
{
	int	i;

	i = nbr / div;
	nbr -= div * i;
	return (nbr);
}
