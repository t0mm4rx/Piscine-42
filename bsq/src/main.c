/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:46:31 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/24 22:37:44 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(int channel, char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(channel, str, i);
}

char	get_char(t_map *map, int i, int j)
{
	if (map->grid[i][j] == 0)
		return (map->empty);
	else if (map->grid[i][j] == 1)
		return (map->obst);
	else
		return (map->full);
}

void	print_grid(t_map *map)
{
	int		i;
	int		j;
	int		x;
	char	buffer[(map->x + 1) * PRINT_LINE_NB + 1];

	j = 0;
	x = 0;
	while (j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			buffer[x++] = get_char(map, i, j);
			i++;
		}
		buffer[x++] = '\n';
		j++;
		if (x >= (map->x + 1) * PRINT_LINE_NB || (i >= map->x || j >= map->y))
		{
			buffer[x] = '\0';
			x = 0;
			ft_putstr(1, buffer);
		}
	}
}

void	process_map(t_map *map)
{
	int x;
	int y;
	int size;

	compute_auxiliary(map);
	biggest_square(map, &x, &y, &size);
	fill_grid_square(&(map->grid), x, y, size);
	print_grid(map);
	free_grid(map);
	free(map);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	int		i;

	if (argc == 1)
	{
		map = map_parse_stdin();
		if (!map)
		{
			ft_putstr(2, "map error\n");
			return (0);
		}
		process_map(map);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			map = map_parse(argv[i++]);
			handle_map(map);
		}
	}
}
