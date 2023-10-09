/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:26:24 by chsiffre          #+#    #+#             */
/*   Updated: 2023/10/09 11:26:11 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_print_line(t_game *game)
{
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = (map->x2 - map->x1);
	delta_y = (map->y2 - map->y1);
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels--)
	{
		if ((int)map->y1 * WIN_W + (int)map->x1 < WIN_W * WIN_H && \
				(int)map->x1 < WIN_W && (int)map->x1 > 0 && \
				(int)map->y1 < WIN_H && (int)map->y1 > 0)
			map->data[(int)map->y1 * WIN_W + (int)map->x1] = ft_color(map);
		game->ray->x += delta_x;
		game->ray->y += delta_y;
	}
}

void	ft_place_line(t_map *map, int y, int x)
{
	map->high = map->tab[y][x];
	if (x + 1 < map->s->column_count)
	{
		map->x2 = (x + 1) * map->size;
		map->y2 = y * map->size;
		map->x1 = x * map->size;
		map->y1 = y * map->size;
		map->high1 = map->tab[y][x + 1];
		ft_print_line(map);
	}
	if (y + 1 < map->s->line_count)
	{
		map->x1 = x * map->size;
		map->y1 = y * map->size;
		map->x2 = x * map->size;
		map->y2 = (y + 1) * map->size;
		map->high1 = map->tab[y + 1][x];
		ft_print_line(map);
	}
}

int	ft_setup_coord(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->data = (int *)
		mlx_get_data_addr(map->image, &map->bpp, &map->size_l, &map->endian);
	while (y < map->s->line_count)
	{
		x = 0;
		while (x < map->s->column_count)
		{
			ft_place_line(map, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->image, 0, 0);
	return (0);
}
// permet de draw la map, ensuite on raycast