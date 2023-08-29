/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:45:18 by lucas             #+#    #+#             */
/*   Updated: 2023/08/29 11:16:27 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	texture_exist(t_game *game)
{
	int	fd;

	fd = open(game->texture.no, O_RDONLY);
	if (fd == -1)
		map_error(game, 0);
	close(fd);
	fd = open(game->texture.so, O_RDONLY);
	if (fd == -1)
		map_error(game, 0);
	close(fd);
	fd = open(game->texture.ea, O_RDONLY);
	if (fd == -1)
		map_error(game, 0);
	close(fd);
	fd = open(game->texture.we, O_RDONLY);
	if (fd == -1)
		map_error(game, 0);
	close(fd);
	return (1);
}

int	get_size(t_game *game)
{
	int		fd;
	char	*line;
	int		size;

	size = 0;
	fd = open(game->map, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	while (line)
	{
		if (line == NULL)
			return (-1);
		free(line);
		line = get_next_line(fd);
		size++;
	}
	close(fd);
	return (size);
}

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
	allocate_texture(game, fd);
	texture_exist(game);
	game->tab_map = allocate_map(game, fd);
	close(fd);
	parse_map(game);
	window_init(game);
}

int	check_name(char	*name)
{
	int	i;

	i = ft_strlen(name);
	if (name[--i] == 'b')
		if (name[--i] == 'u')
			if (name[--i] == 'c')
				if (name[--i] == '.')
					return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf("Error\n"), 1);
	else if (check_name(argv[1]) == 0)
		return (printf("Error\n"), 1);
	game.count = 0;
	game.map = argv[1];
	game_init(&game);
	return (0);
}
