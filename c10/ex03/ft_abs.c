/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 23:17:44 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/18 15:58:57 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	ft_abs(char c)
{
	return (c < 0 ? -c : c);
}

#include <stdio.h>
void	ft(char buffer[16], int is_option_c, int data[3])
{
	handle_buffer(buffer, is_option_c, data[2], data[0]);
	write(1, "\n", 1);
}

void	copy_buffer(char dest[16], char src[16])
{
	int i;

	i = 0;
	while (i < 16)
	{
		dest[i] = src[i];
		i++;
	}
}

int		buffer_cmp(char b1[16], char b2[16])
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (b1[i] != b2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
