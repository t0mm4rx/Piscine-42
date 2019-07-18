/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:32:52 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/18 17:16:57 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
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
			if (ft_abs(buffer[i]) <= 15 && buffer[i] != (char)128)
				write(1, "0", 1);
			if (buffer[i] == (char)128)
				write(1, "80", 2);
			else
				ft_putnbr_base(ft_abs((unsigned int)buffer[i]),
						"0123456789abcdef");
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

void	ft_print_memory(char *file, int is_option_c, char *file_after, int a)
{
	int		fd;
	char	buffer[16];
	char	last_buffer[16];
	int		data[3];
	int		a;

	data[0] = 0;
	a = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("ft_hexdump");
		ft_putstr(": ");
		ft_putstr(file);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		write(1, "\n", 1);
		return ;
	}
	while ((data[2] = read(fd, buffer, 16)) > 0)
	{
		if (data[2] < 16 && file_after[0] != '\0')
		{
			fd = open(1);
			
		}
		if (buffer_cmp(last_buffer, buffer) == 0)
		{
			ft(buffer, is_option_c, data);
			copy_buffer(last_buffer, buffer);
			a = 0;
		}
		else
		{
			if (a++ == 0)
				write(1, "*\n", 2);
		}
		data[0] += data[2];
	}
	ft_print_address(data[0], is_option_c);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int i;
	int is_option_c;
	int valid_count;
	int fd;

	i = 1;
	is_option_c = 0;
	valid_count = 0;
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'C' &&
			argv[1][2] == '\0')
	{
		i++;
		is_option_c = 1;
	}
	if (argc == 1 + is_option_c)
	{
		ft_read_stdin(is_option_c);
		return (0);
	}
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) != -1)
			valid_count++;
		close(fd);
		ft_print_memory(argv[i], is_option_c);
		if (valid_count == 0 && i == argc - 1)
		{
			ft_putstr("ft_hexdump");
			ft_putstr(": ");
			ft_putstr(argv[i]);
			ft_putstr(": ");
			ft_putstr("Bad file descriptor\n");
		}
		i++;
	}
	return (0);
}
