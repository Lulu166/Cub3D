/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:11:04 by chsiffre          #+#    #+#             */
/*   Updated: 2023/09/05 14:27:42 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	game_init(t_game *game, char *arg)
{
	int	fd;


	game->count = 0;
	game->map = arg;
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
	init_ray_struct(game);
	allocate_texture(game, fd);
	texture_exist(game);
	game->tab_map = allocate_map(game, fd);
	close(fd);
	parse_map(game);
	window_init(game);
}

void    init_ray_struct(t_game *g)
{
    printf("ok\n");
    g->ray = malloc(sizeof(t_ray));
    if (!g->ray)
        return  ;
    g->ray->posX = 22;
    g->ray->posY = 12;
    g->ray->dirX = -1;
    g->ray->dirY = 0;
    g->ray->time = 0;
    g->ray->old_time = 0;
    g->ray->planeX = 0;
    g->ray->planeY = 0.66;
    g->ray->cameraX = 0.0;
    g->ray->raydirX = 0;
    g->ray->raydirY = 0;
    g->ray->mapX = 0;
    g->ray->mapY = 0;
    g->ray->lengthray_X = 0;
    g->ray->lengthray_Y = 0;
    g->ray->time = 0;
    g->ray->old_time = 0;
    g->ray->side = 0;
    g->ray->hit = 0;
    g->ray->stepX = 0;
    g->ray->stepY = 0;
    g->ray->deltaX = 0;
    g->ray->deltaY = 0;
    g->ray->DrawEnd = 0;
    g->ray->DrawStart = 0;
}
