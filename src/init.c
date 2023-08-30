/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:11:04 by chsiffre          #+#    #+#             */
/*   Updated: 2023/08/30 11:49:25 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	game_init(t_game *game)
{
	int	fd;

	game->map_size = get_size(game);
	game->texture.no = NULL;
	game->texture.so = NULL;
	game->texture.we = NULL;
	game->texture.ea = NULL;
	game->texture.c = NULL;
	game->texture.f = NULL;
	fd = open(game->map, O_RDONLY);
	if (fd == -1)
		return ;
	init_ray_struct(game->ray);
	allocate_texture(game, fd);
	texture_exist(game);
	game->tab_map = allocate_map(game, fd);
	close(fd);
	parse_map(game);
	window_init(game);
}

void    init_ray_struct(t_ray *ray)
{
    ray->posX = 22;
    ray->posY = 12;
    ray->dirX = -1;
    ray->dirY = 0;
    ray->time = 0;
    ray->old_time = 0;
    ray->planeX = 0;
    ray->planeY = 0.66;
    ray->cameraX = 0;
    ray->raydirX = 0;
    ray->raydirY = 0;
    ray->mapX = 0;
    ray->mapY = 0;
    ray->lengthray_X = 0;
    ray->lengthray_Y = 0;
    ray->time = 0;
    ray->old_time = 0;
    ray->side = 0;
    ray->hit = 0;
    ray->stepX = 0;
    ray->stepY = 0;
    ray->deltaX = 0;
    ray->deltaY = 0;
}
