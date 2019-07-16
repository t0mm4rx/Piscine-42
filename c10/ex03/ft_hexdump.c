/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:32:52 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/16 20:08:51 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_print_address(int addr, int is_option_c)
{
	int zero_count;
	int i;

	zero_count = 7 - ft_get_hex_length(addr);
	if (is_option_c)
		zero_count++;
	i = 0;
	while (i < zero_count)
	{
		write(1, "0", 1);
		i++;
	}
	ft_putnbr_base(addr, "0123456789abcdef");
}

void	ft_print_memory_block(char buffer[16], int is_option_c, int max_n)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i < max_n)
		{
			if (buffer[i] < (char)15)
				write(1, "0", 1);
			ft_putnbr_base(buffer[i], "0123456789abcdef");
		}
		else
			write(1, "  ", 2);
		if (i != 15)
			write(1, " ", 1);
		if (is_option_c && i == 7)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_ascii(char buffer[16], int max_n)
{
	int i;

	write(1, "|", 1);
	i = 0;
	while (i < max_n)
	{
		if (ft_char_is_printable(buffer[i]))
			write(1, &buffer[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|", 1);
}

void	ft_print_memory(char *file, int is_option_c)
{
	int		fd;
	int		n;
	int		addr;
	char	buffer[16];

	addr = 0;
	n = 0;
	fd = open(file, O_RDONLY);
	while ((n = read(fd, buffer, 16)) > 0)
	{
		ft_print_address(addr, is_option_c);
		if (is_option_c)
			write(1, "  ", 2);
		else
			write(1, " ", 1);
		ft_print_memory_block(buffer, is_option_c, n);
		if (is_option_c)
		{
			write(1, "  ", 2);
			ft_print_ascii(buffer, n);
		}
		write(1, "\n", 1);
		addr += n;
	}
	ft_print_address(addr, is_option_c);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int i;
	int is_option_c;

	i = 1;
	is_option_c = 0;
	if (argv[1][0] == '-' && argv[1][1] == 'C' && argv[1][2] == '\0')
	{
		i++;
		is_option_c = 1;
	}
	while (i < argc)
	{
		ft_print_memory(argv[i++], is_option_c);
	}
	return (0);
}
