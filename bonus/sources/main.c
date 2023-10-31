/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:45:18 by lucas             #+#    #+#             */
/*   Updated: 2023/10/31 15:07:48 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	get_size(t_game *game)
{
	char	*line;
	int		size;

	size = 0;
	game->fd = open(game->map, O_RDONLY);
	if (game->fd == -1)
		return (-1);
	line = get_next_line(game->fd);
	if (line == NULL)
		return (-1);
	while (line)
	{
		if (line == NULL)
			return (-1);
		free(line);
		line = get_next_line(game->fd);
		size++;
	}
	close(game->fd);
	return (size);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\n"), 1);
	else if (check_name(argv[1]) == 0)
		return (ft_printf("Error\n"), 1);
	game_init(&game, argv[1]);
	return (0);
}
