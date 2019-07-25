/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:59:34 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/24 17:41:31 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		handle_first_line(char buffer[FIRST_LINE_BUFFER], t_map *map)
{
	int i;

	i = 0;
	if (buffer[0] < '0' || buffer[0] > '9')
		return (0);
	while (buffer[i] && buffer[i] != '\n' && i < 20)
		i++;
	if (i >= 20 || i < 3)
		return (0);
	i -= 3;
	map->empty = buffer[i++];
	map->obst = buffer[i++];
	map->full = buffer[i];
	i -= 2;
	buffer[i] = '\0';
	map->y = ft_atoi(buffer);
	return (1);
}

int		parse_first_line(int fd, t_map *map)
{
	char	buffer[FIRST_LINE_BUFFER];
	char	buffer_1[1];
	int		i;

	i = 0;
	while (read(fd, buffer_1, 1) && buffer_1[0] != '\n'
			&& i < FIRST_LINE_BUFFER)
	{
		if (buffer_1[0] < 32 || buffer_1[0] > 127)
			return (0);
		buffer[i++] = buffer_1[0];
	}
	if (!handle_first_line(buffer, map))
		return (0);
	return (1);
}

int		read_file(char *file, t_map *map)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	if (!parse_first_line(fd, map))
		return (0);
	if (!parse_grid(fd, map))
		return (0);
	close(fd);
	return (1);
}

t_map	*map_parse(char *file)
{
	t_map *map;

	if (!(map = malloc(sizeof(t_map))))
		return (0);
	if (!read_file(file, map))
	{
		free(map);
		return (0);
	}
	return (map);
}

t_map	*map_parse_stdin(void)
{
	t_map *map;

	if (!(map = malloc(sizeof(t_map))))
		return (0);
	if (!parse_first_line(0, map))
	{
		free(map);
		return (0);
	}
	if (!parse_grid(0, map))
	{
		free(map);
		return (0);
	}
	return (map);
}
