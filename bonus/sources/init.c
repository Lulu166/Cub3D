/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:11:04 by chsiffre          #+#    #+#             */
/*   Updated: 2023/10/31 16:24:42 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	game_file(t_game *game)
{
	game->fd = open(game->map, O_RDONLY);
	if (game->fd == -1)
	{
		ft_printf("Error\n");
		exit (1);
	}
	allocate_texture(game, game->fd);
	texture_exist(game);
	game->tab_map = allocate_map(game, game->fd);
	close(game->fd);
	if (game->tab_map == NULL)
		map_error(game, 0, 0, 2);
}

void	set_angle(t_game *game)
{
	if (game->player.orientation == 'N')
		game->angle = M_PI / 2;
	else if (game->player.orientation == 'W')
		game->angle = M_PI;
	else if (game->player.orientation == 'S')
		game->angle = 3 * M_PI / 2;
	else if (game->player.orientation == 'E')
		game->angle = 2 * M_PI;
}

void	game_init(t_game *game, char *arg)
{
	game->nb_xpm = 0;
	game->angle = 0;
	game->sin_angle = sin(game->angle);
	game->cos_angle = cos(game->angle);
	game->line_count = 0;
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
	set_angle(game);
	window_init(game);
}

void	init_ray(t_game *g, t_pointf *xy_v, t_pointf *xy_h)
{
	g->collision[0] = 0;
	g->collision[1] = 0;
	xy_v->x = 0;
	xy_v->y = 0;
	xy_h->x = 0;
	xy_h->y = 0;
	g->cos_angle = cosf(g->ray->ray_angle);
	g->sin_angle = -sinf(g->ray->ray_angle);
}

void	init_ray_struct(t_game *g)
{
	g->ray->pos_x = g->player.pos_x + 8;
	g->ray->pos_y = g->player.pos_y + 8;
	g->ray->dir_x = -1;
	g->ray->dir_y = 0;
	g->ray->map_x = 0;
	g->ray->map_y = 0;
	g->ray->adjacent = 0;
	g->ray->opposit = 0;
	g->ray->ray_angle = 0;
	g->ray->x = 1;
}
