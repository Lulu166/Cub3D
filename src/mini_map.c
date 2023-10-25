/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:56 by luhumber          #+#    #+#             */
/*   Updated: 2023/10/25 14:29:48 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// float	throw_ray(t_game *g, float x_start, float y_start, float angle)
// {
// 	t_pointf	first_xy;
// 	t_pointf	step;
// 	t_point		xy;
// 	float		dist;
	
// 	dist = 0;
// 	xy.x = x_start + step.x * g->cos_angle;
// 	xy.y = y_start + step.y * g->sin_angle;
// 	first_xy.x = xy.x;
// 	first_xy.y = xy.y;
// 	while (1)
// 	{
// 		if (g->tab_map[((int) g->ray->dirY >> 4)][((((int) g->ray->dirX)) >> 4)] == '1' || g->tab_map[((int) g->ray->dirY >> 4)][(int) (g->ray->dirX) >> 4] == '1' || g->tab_map[(int)(g->ray->dirY + 1) >> 4][(int) g->ray->dirX >> 4] == '1')
// 			break;
// 		step.x += 1;
// 		xy.x = x_start + step.x * g->cos_angle / 10;
// 		step.y += 1;
// 		xy.y = y_start + step.y * g->sin_angle / 10;
// 		//my_mlx_pixel_put(g->data, g->ray->dirX, g->ray->dirY, 0x000080);
// 	}
// 	return (dist);
// }

void	mini_line(t_game *game, int i, int j)
{
	if (game->tab_map[i][j] == '0')
		draw_square(game, game->height, game->lenght, 0x808080);
	else if (game->tab_map[i][j] == '1')
		draw_square(game, game->height, game->lenght, 0xB03030);
	draw_circle
	(game, game->player.posy - 3, game->player.posx - 3, game->player.color);
	game->lenght += 16;
}

void	mini_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->height = 0;
	while (game->tab_map[i] && game->height <= WIN_H)
	{
		game->lenght = 0;
		j = 0;
		while (game->tab_map[i][j] && game->lenght <= WIN_W)
			mini_line(game, i, j++);
		i++;
		game->height += 16;
	}
}
