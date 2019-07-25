/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 08:18:38 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/24 17:38:56 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		fill_row(char buffer[X_BUFFER], t_map *map, int y)
{
	int i;

	i = 0;
	if (y > map->y - 1)
		return (0);
	while (buffer[i] && (buffer[i] == map->empty || buffer[i] == map->obst)
			&& i < map->x)
	{
		if (buffer[i] == map->empty)
			map->grid[i][y] = 0;
		else if (buffer[i] == map->obst)
			map->grid[i][y] = 1;
		else
			return (0);
		i++;
	}
	if (i != map->x)
		return (0);
	return (1);
}

int		parse_first_grid_line(int fd, t_map *map)
{
	int		i;
	char	buffer[X_BUFFER];
	char	buffer_1[1];

	(void)map;
	i = 0;
	while (read(fd, buffer_1, 1) > 0 && buffer_1[0] && buffer_1[0] != '\n')
	{
		buffer[i++] = buffer_1[0];
	}
	buffer[i] = '\0';
	map->x = i;
	create_grid(map->x, map->y, &(map->grid), 0);
	create_grid(map->x, map->y, &(map->grid_copy), 1);
	return (fill_row(buffer, map, 0));
}

int		parse_body_grid(int fd, t_map *map)
{
	int		i;
	char	buffer[map->x + 2];

	i = 1;
	while (read(fd, buffer, map->x + 1))
	{
		if (!fill_row(buffer, map, i++))
			return (0);
	}
	if (i != map->y)
		return (0);
	return (1);
}

int		parse_grid(int fd, t_map *map)
{
	if (!parse_first_grid_line(fd, map))
		return (0);
	if (!parse_body_grid(fd, map))
		return (0);
	return (1);
}
