/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:30:37 by chsiffre          #+#    #+#             */
/*   Updated: 2023/10/25 16:02:24 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float   check_vertical(t_game *game, t_pointf *xy)
{
    float dist;

    dist = 0.0;
		if (game->cos_angle >= 0)
			dist = vertical_pos(game, xy);
		else if (game->cos_angle < 0)
			dist = vertical_neg(game, xy);	
	return (dist);
}

float   vertical_pos(t_game *game, t_pointf *xy)
{
    float		depth_y;
	float		delta_depth;

	xy->y = 0;
	xy->x = 0;
	depth_y = 0;
	while (xy->x <= game->ray->posX)
		xy->x += 16;
	depth_y = (xy->x - game->ray->posX) / game->cos_angle;
	xy->y = game->ray->posY + depth_y * game->sin_angle;
	delta_depth = (16 / game->cos_angle) * game->sin_angle;
	while ((xy->x / 16) > 0 && (xy->y / 16) > 0 && \
	(xy->y / 16) < map_size(game) && \
	(xy->x / 16) < game->column_count[(int)(xy->y) / 16] && \
	(game->tab_map[(int)(xy->y) / 16][(int)(xy->x) / 16] != '1'))
	{
		xy->y += delta_depth;
		xy->x += 16;
	}
	return (sqrt(powf((game->ray->posX - xy->x), 2) + \
	powf((game->ray->posY - xy->y), 2)));
}

float   vertical_neg(t_game *game, t_pointf *xy)
{
    float		depth_y;
	float		delta_depth;

	xy->y = 0;
	xy->x = 0;
	depth_y = 0;
	while (xy->x <= game->ray->posX)
		xy->x += 16;
	xy->x -= 16;
	depth_y = (xy->x - game->ray->posX) / game->cos_angle + 0.000000001;
	xy->y = game->ray->posY + depth_y * game->sin_angle;
	delta_depth = (16 / -game->cos_angle) * game->sin_angle;
	while (((xy->x - 0.000000001) / 16) > 0 && ((xy->y - 0.000000001) / 16) > 0 && \
	((xy->y - 0.000000001) / 16) < map_size(game) && \
	((xy->x - 0.000000001) / 16) < game->column_count[(int)((xy->y - 0.000000001)) / 16] && \
	(game->tab_map[(int)((xy->y - 0.000000001)) / 16][(int)((xy->x - 0.000000001)) / 16] != '1'))
	{
		xy->y += delta_depth;
		xy->x -= 16;
	}
	return (sqrt(powf((game->ray->posX - xy->x), 2) + \
	powf((game->ray->posY - xy->y), 2)));
}