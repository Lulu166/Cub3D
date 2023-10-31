/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:30:32 by chsiffre          #+#    #+#             */
/*   Updated: 2023/10/31 16:23:01 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

float	check_horizontal(t_game *game, t_pointf *xy)
{
	float	dist;

	dist = 0.0;
	if (game->sin_angle < 0)
		dist = horizontal_pos(game, xy);
	else if (game->sin_angle >= 0)
		dist = horizontal_neg(game, xy);
	return (dist);
}

float	horizontal_pos(t_game *game, t_pointf *xy)
{
	float		depth_x;
	float		delta_depth;

	xy->y = 0;
	depth_x = 0;
	while (xy->y <= game->ray->pos_y)
		xy->y += 32;
	xy->y -= 32;
	depth_x = (xy->y - game->ray->pos_y) / game->sin_angle;
	xy->x = game->ray->pos_x + depth_x * game->cos_angle + 0.000000001;
	delta_depth = (32 / -game->sin_angle) * game->cos_angle;
	while (((xy->x - 0.000000001) / 32) > 0
		&& ((xy->y - 0.000000001) / 32) > 0 && \
		((xy->y - 0.000000001) / 32) < map_size(game) && \
		((xy->x - 0.000000001) / 32) < game->column_count[(int)
			((xy->y - 0.000000001)) / 32] && \
		(game->tab_map[(int)((xy->y - 0.000000001)) / 32]
		[(int)((xy->x - 0.000000001)) / 32] != '1'))
	{
		xy->x += delta_depth;
		xy->y -= 32;
	}
	return (sqrt(powf((game->ray->pos_x - xy->x), 2) + \
	powf((game->ray->pos_y - xy->y), 2)));
}

float	horizontal_neg(t_game *game, t_pointf *xy)
{
	float		depth_x;
	float		delta_depth;

	xy->y = 0;
	xy->x = 0;
	depth_x = 0;
	while (xy->y <= game->ray->pos_y)
		xy->y += 32;
	depth_x = (xy->y - game->ray->pos_y) / game->sin_angle;
	xy->x = game->ray->pos_x + depth_x * game->cos_angle;
	delta_depth = (32 / game->sin_angle) * game->cos_angle;
	while ((xy->x / 32) > 0 && (xy->y / 32) > 0 && \
	(xy->y / 32) < map_size(game) && \
	(xy->x / 32) < game->column_count[(int)(xy->y) / 32] && \
	(game->tab_map[(int)(xy->y) / 32][(int)(xy->x) / 32] != '1'))
	{
		xy->x += delta_depth;
		xy->y += 32;
	}
	return (sqrt(powf((game->ray->pos_x - xy->x), 2) + \
		powf((game->ray->pos_y - xy->y), 2)));
}
