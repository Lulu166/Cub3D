/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:30:32 by chsiffre          #+#    #+#             */
/*   Updated: 2023/10/31 15:06:08 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

float   check_horizontal(t_game *game, t_pointf *xy)
{
    float dist;

	dist = 0.0;
		if (game->sin_angle < 0)
			dist = horizontal_pos(game, xy);
		else if (game->sin_angle >= 0)
			dist = horizontal_neg(game, xy);
    return (dist);
}

float horizontal_pos(t_game *game, t_pointf *xy)
{
    float		depth_x;
	float		delta_depth;

	xy->y = 0;
	depth_x = 0;
	while (xy->y <= game->ray->posY)
		xy->y += 16;
	xy->y -= 16;
	depth_x = (xy->y - game->ray->posY) / game->sin_angle;
	xy->x = game->ray->posX + depth_x * game->cos_angle + 0.000000001;
	delta_depth = (32 / -game->sin_angle) * game->cos_angle;
	while (((xy->x - 0.000000001) / 16)  > 0 && ((xy->y - 0.000000001) / 16)  > 0 && \
	((xy->y - 0.000000001) / 16)  < map_size(game) && \
	((xy->x - 0.000000001) / 16)  < game->column_count[(int)((xy->y - 0.000000001)) / 16] && \
	(game->tab_map[(int)((xy->y - 0.000000001)) / 16][(int)((xy->x - 0.000000001)) / 16] != '1'))
	{
		xy->x += delta_depth;
		xy->y -= 16;
	}
    return(sqrt(powf((game->ray->posX - xy->x), 2) + \
    powf((game->ray->posY - xy->y), 2)));
}

float horizontal_neg(t_game *game, t_pointf *xy)
{
    float		depth_x;
	float		delta_depth;

	xy->y = 0;
	xy->x = 0;
	depth_x = 0;
	while (xy->y <= game->ray->posY)
		xy->y += 16;
	depth_x = (xy->y - game->ray->posY) / game->sin_angle;
	xy->x = game->ray->posX + depth_x * game->cos_angle;
	delta_depth = (32 / game->sin_angle) * game->cos_angle;
	while ((xy->x / 16) > 0 && (xy->y / 16) > 0 && \
	(xy->y / 16) < map_size(game) && \
	(xy->x / 16) < game->column_count[(int)(xy->y) / 16] && \
	(game->tab_map[(int)(xy->y) / 16][(int)(xy->x) / 16] != '1'))
	{
		xy->x += delta_depth;
		xy->y += 16;
	}
    return(sqrt(powf((game->ray->posX - xy->x), 2) + \
    powf((game->ray->posY -  xy->y), 2)) );

}