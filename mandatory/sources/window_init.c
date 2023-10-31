/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:05:41 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/31 13:02:59 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	hook_reload(t_game *game)
{
	can_move(game);
	can_turn(game);
	can_mouse(game);
	mlx_destroy_image(game->screen.mlx, game->data->img);
	game->data->img = mlx_new_image(game->screen.mlx, WIN_W, WIN_H);
	mlx_clear_window(game->screen.mlx, game->screen.win);
	draw_map(game);
	if (game->mini_map == 1)
		mini_map(game);
	mlx_put_image_to_window
		(game->screen.mlx, game->screen.win, game->data->img, 0, 0);
	return (0);
}

void	game_loop(t_game *game)
{
	mlx_hook(game->screen.win, 17, 0L, close_window, game);
	mlx_hook(game->screen.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->screen.win, 6, 1L << 6, mouse_hook, game);
	mlx_mouse_hook(game->screen.win, mouse_click, game);
	mlx_hook(game->screen.win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->screen.mlx, hook_reload, game);
	mlx_loop(game->screen.mlx);
}

void	texture_addr(t_game *game)
{
	game->tex.no_img.data.addr = mlx_get_data_addr(game->tex.no_img.xpm_tex,
			&game->tex.no_img.data.bpr, &game->tex.no_img.data.len,
			&game->tex.no_img.data.endian);
	if (!game->tex.no_img.data.addr)
		map_error(game, 3, 3, 4);
	game->tex.so_img.data.addr = mlx_get_data_addr(game->tex.so_img.xpm_tex,
			&game->tex.so_img.data.bpr, &game->tex.so_img.data.len,
			&game->tex.so_img.data.endian);
	if (!game->tex.so_img.data.addr)
		map_error(game, 3, 3, 4);
	game->tex.we_img.data.addr = mlx_get_data_addr(game->tex.we_img.xpm_tex,
			&game->tex.we_img.data.bpr, &game->tex.we_img.data.len,
			&game->tex.we_img.data.endian);
	if (!game->tex.we_img.data.addr)
		map_error(game, 3, 3, 4);
	game->tex.ea_img.data.addr = mlx_get_data_addr(game->tex.ea_img.xpm_tex,
			&game->tex.ea_img.data.bpr, &game->tex.ea_img.data.len,
			&game->tex.ea_img.data.endian);
	if (!game->tex.ea_img.data.addr)
		map_error(game, 3, 3, 4);
}

void	texture_to_xpm(t_game *game)
{
	game->tex.no_img.xpm_tex = mlx_xpm_file_to_image(game->screen.mlx,
			game->tex.no, &game->tex.no_img.x, &game->tex.no_img.y);
	if (!game->tex.no_img.xpm_tex)
		map_error(game, 3, 3, 4);
	game->nb_xpm++;
	game->tex.so_img.xpm_tex = mlx_xpm_file_to_image(game->screen.mlx,
			game->tex.so, &game->tex.so_img.x, &game->tex.so_img.y);
	if (!game->tex.so_img.xpm_tex)
		map_error(game, 3, 3, 4);
	game->nb_xpm++;
	game->tex.we_img.xpm_tex = mlx_xpm_file_to_image(game->screen.mlx,
			game->tex.we, &game->tex.we_img.x, &game->tex.we_img.y);
	if (!game->tex.we_img.xpm_tex)
		map_error(game, 3, 3, 4);
	game->nb_xpm++;
	game->tex.ea_img.xpm_tex = mlx_xpm_file_to_image(game->screen.mlx,
			game->tex.ea, &game->tex.ea_img.x, &game->tex.ea_img.y);
	if (!game->tex.ea_img.xpm_tex)
		map_error(game, 3, 3, 4);
	game->nb_xpm++;
	texture_addr(game);
}

void	window_init(t_game *game)
{
	game->data = (t_data *)malloc(sizeof(t_data));
	if (!game->data)
		map_error(game, 1, 0, 0);
	if (!fill_column_count(game))
		map_error(game, 1, 0, 2);
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		map_error(game, 2, 0, 0);
	game->screen.mlx = mlx_init();
	if (!game->screen.mlx)
		map_error(game, 2, 0, 0);
	game->screen.win = mlx_new_window(game->screen.mlx, WIN_W, WIN_H, "Cub3D");
	if (!game->screen.win)
		map_error(game, 2, 1, 0);
	game->data->img = mlx_new_image(game->screen.mlx, WIN_W, WIN_H);
	if (!game->data->img)
		map_error(game, 2, 2, 4);
	game->data->addr = mlx_get_data_addr
		(game->data->img, &game->data->bpr,
			&game->data->len, &game->data->endian);
	if (!game->data->addr)
		map_error(game, 2, 3, 4);
	texture_to_xpm(game);
	game_loop(game);
}
