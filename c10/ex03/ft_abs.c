/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 23:17:44 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/17 13:15:52 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	ft_abs(char c)
{
	return (c < 0 ? -c : c);
}

void	ft(char buffer[16], int is_option_c, int data[3])
{
	if (data[0] > 0 && is_buffer_empty(buffer))
		data[1]++;
	if (!data[1] || !is_buffer_empty(buffer))
	{
		if (data[1] > 1)
			write(1, "*\n", 2);
		data[1] = 0;
		handle_buffer(buffer, is_option_c, data[2], data[0]);
		if (is_buffer_empty(buffer) && !data[1])
			data[1]++;
		write(1, "\n", 1);
	}
}
