/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:08:26 by luhumber          #+#    #+#             */
/*   Updated: 2023/09/04 13:32:58 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	can_move(t_game *game)
{
	if (game->player.top == 1)
	{
		game->player.height -= 2;
		game->player.top = 0;
	}
	if (game->player.right == 1)
	{
		game->player.lenght += 2;
		game->player.right = 0;
	}
	if (game->player.down == 1)
	{
		game->player.height += 2;
		game->player.down = 0;
	}
	if (game->player.left == 1)
	{
		game->player.lenght -= 2;
		game->player.left = 0;
	}
	return (0);
}
