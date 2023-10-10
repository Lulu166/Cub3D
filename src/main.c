/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:45:18 by lucas             #+#    #+#             */
/*   Updated: 2023/10/10 15:10:18 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_extension(t_game *game, char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[--i] == 'm')
		if (str[--i] == 'p')
			if (str[--i] == 'x')
				if (str[--i] == '.')
					return ;
	map_error(game, 0);
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

int	texture_exist(t_game *game)
{
	int	fd;

	check_extension(game, game->tex.no);
	fd = open(game->tex.no, O_RDONLY);
	if (fd == -1)
		map_error(game, 0);
	close(fd);
	check_extension(game, game->tex.so);
	fd = open(game->tex.so, O_RDONLY);
	if (fd == -1)
		map_error(game, 0);
	close(fd);
	check_extension(game, game->tex.ea);
	fd = open(game->tex.ea, O_RDONLY);
	if (fd == -1)
		map_error(game, 0);
	close(fd);
	check_extension(game, game->tex.we);
	fd = open(game->tex.we, O_RDONLY);
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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf("Error\n"), 1);
	else if (check_name(argv[1]) == 0)
		return (printf("Error\n"), 1);
	game_init(&game, argv[1]);
	return (0);
}
