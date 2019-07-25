/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:26:01 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/24 22:07:32 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_first_lines(t_map *map)
{
	int i;

	i = 0;
	while (i < map->x)
	{
		if (map->grid[i][0] == 0)
			map->grid_copy[i][0] = 1;
		else
			map->grid_copy[i][0] = 0;
		i++;
	}
	i = 0;
	while (i < map->y)
	{
		if (map->grid[0][i] == 0)
			map->grid_copy[0][i] = 1;
		else
			map->grid_copy[0][i] = 0;
		i++;
	}
}

void	compute_auxiliary(t_map *map)
{
	int i;
	int j;

	fill_first_lines(map);
	j = 1;
	while (j < map->y)
	{
		i = 1;
		while (i < map->x)
		{
			if (map->grid[i][j] == 0)
			{
				map->grid_copy[i][j] = min(map->grid_copy[i][j - 1],
						map->grid_copy[i - 1][j],
						map->grid_copy[i - 1][j - 1]) + 1;
			}
			else
				map->grid_copy[i][j] = 0;
			i++;
		}
		j++;
	}
}

void	biggest_square(t_map *map, int *top_i, int *left_i, int *size)
{
	int i;
	int j;
	int max;

	j = map->y - 1;
	max = 0;
	while (j >= 0)
	{
		i = map->x - 1;
		while (i >= 0)
		{
			if (map->grid_copy[i][j] >= max)
			{
				max = map->grid_copy[i][j];
				*top_i = i;
				*left_i = j;
				*size = max;
			}
			i--;
		}
		j--;
	}
}

void	fill_grid_square(int ***grid, int x, int y, int size)
{
	int i;
	int j;

	(void)grid;
	j = y;
	while (j > y - size)
	{
		i = x;
		while (i > x - size)
		{
			(*grid)[i][j] = 2;
			i--;
		}
		j--;
	}
}
