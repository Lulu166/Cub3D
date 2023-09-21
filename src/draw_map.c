/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:26:24 by chsiffre          #+#    #+#             */
/*   Updated: 2023/09/20 13:36:33 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		draw_map(t_game *game)
{
	float	x;
	float	y;
	int		color;
	float	i;
	float	j;

	y = -1;
	j = 0;
	while (++y < game->width * 0.15 && (i = 0) == 0)
	{
		x = -1;
		while (++x < (data->width * 0.15))
		{
			if ((int)i == (int)data->pos_y && (int)j == (int)data->pos_x)
				color = 16711680;
			else if (data->map[(int)j][(int)i] == 0)
				color = 16448250;
			else
				color = 0;
			if (color != 0)
				data->img.data[(int)x + (int)y * data->width] = color;
			i += (float)(data->map_width / (data->width * 0.15));
		}
		j += (float)data->map_height / (data->width * 0.15);
	}
}
// permet de draw la map, ensuite on raycast