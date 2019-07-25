/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:35:37 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/24 22:37:20 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_grid(int x, int y, int ***grid, int is_aux)
{
	int i;
	int j;

	i = 0;
	*grid = malloc(sizeof(int*) * x);
	while (i < x)
	{
		(*grid)[i] = malloc(sizeof(int) * y);
		i++;
	}
	i = 0;
	j = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			(*grid)[i][j] = is_aux;
			j++;
		}
		i++;
	}
}

void	free_grid(t_map *map)
{
	int i;

	i = 0;
	while (i < (map->x))
	{
		free(map->grid[i]);
		free(map->grid_copy[i++]);
	}
	free(map->grid);
	free(map->grid_copy);
}

int		min(int a, int b, int c)
{
	int m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

void	handle_map(t_map *map)
{
	if (!map)
	{
		ft_putstr(2, "map error\n");
	}
	else
	{
		process_map(map);
	}
}
