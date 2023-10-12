/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:11:04 by chsiffre          #+#    #+#             */
/*   Updated: 2023/10/12 17:32:23 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	game_file(t_game *game)
{
	int	fd;

	fd = open(game->map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		exit (1);
	}
	allocate_texture(game, fd);
	texture_exist(game);
	game->tab_map = allocate_map(game, fd);
	close(fd);
	if (game->tab_map == NULL)
		map_error(game, 0, 0);
}

void	game_init(t_game *game, char *arg)
{
	game->angle = 0; // a changer en fonction de l'orientation
	game->sin_angle = sin(game->angle);
	game->cos_angle = cos(game->angle);
	game->count = 0;
	game->map = arg;
	game->map_size = get_size(game);
	game->tex.no = NULL;
	game->tex.so = NULL;
	game->tex.we = NULL;
	game->tex.ea = NULL;
	game->tex.c = 0;
	game->tex.f = 0;
	game->mini_map = 0;
	game_file(game);
	parse_map(game);
	window_init(game);
}

void    init_ray_struct(t_game *g)
{
	g->ray = malloc(sizeof(t_ray));
	if (!g->ray)
		map_error(g, 2, 3);
	g->ray->posX = g->player.posx;
	g->ray->posY = g->player.posy;
	g->ray->dirX = -1;
	g->ray->dirY = 0;
	g->ray->time = 0;
	g->ray->old_time = 0;
	g->ray->mapX = 0;
	g->ray->x = 1;
	g->ray->mapY = 0;
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
