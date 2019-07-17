/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 23:23:42 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/17 02:12:02 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_buffer(char buffer[16], int is_option_c, int max_n, int addr)
{
	ft_print_address(addr, is_option_c);
	if (is_option_c)
		write(1, "  ", 2);
	else
		write(1, " ", 1);
	ft_print_memory_block(buffer, is_option_c, max_n);
	if (is_option_c)
	{
		write(1, "  ", 2);
		ft_print_ascii(buffer, max_n);
	}
}
