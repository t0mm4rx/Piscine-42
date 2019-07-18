/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 23:59:57 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/18 14:50:36 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_read_stdin(int is_option_c)
{
	char	buffer[32000];
	int		data[3];
	
	data[0] = 0;
	data[1] = 0;
	while ((data[2] = read(0, buffer, 16)) > 0)
	{
		ft(buffer, is_option_c, data);
		data[0] += data[2];
	}
	ft_print_address(data[0], is_option_c);
	write(1, "\n", 1);
}