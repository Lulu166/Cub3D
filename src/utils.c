/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:35:43 by lucas             #+#    #+#             */
/*   Updated: 2023/08/20 17:04:55 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	compare_str(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while ((i < len) && (s1[i] || s2[i]))
	{
		if ((s1[i] != s2[i]) || (s2[i] != s1[i]))
			return (0);
		i++;
	}
	return (1);
}

int		valid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\r' || line[i] == '\v' || line[i] == '\f')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	else
		return (0);
}
