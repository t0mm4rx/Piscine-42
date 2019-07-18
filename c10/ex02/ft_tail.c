/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 00:19:24 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/19 01:52:41 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_header(char *file)
{
	ft_putstr(1, "==> ");
	ft_putstr(1, file);
	ft_putstr(1, " <==\n");
}

int		file_length(char *file, int display_error, char *program_name)
{
	int		fd;
	int		res;
	int		n;
	char	buffer[1];

	res = 0;
	if ((fd = open(file, 0)) == -1)
	{
		if (display_error > 0)
		{
			ft_putstr(2, program_name);
			ft_putstr(2, ": ");
			ft_putstr(2, file);
			ft_putstr(2, ": No such file or directory");
			if (display_error == 1)
				ft_putstr(2, "\n");
		}
		return (-1);
	}
	while ((n = read(fd, buffer, 1)) > 0)
		res += n;
	return (res);
}

void	process_file(char *file, int ddh, int char_count, int i, char *pn)
{
	int		fd;
	char	buffer[1];
	int		n;
	int		res;
	int		offset;

	res = 0;
	offset = file_length(file, 1 + i, pn) - char_count;
	fd = open(file, 0);
	if (ddh && fd != -1)
		display_header(file);
	while ((n = read(fd, buffer, 1)) > 0)
	{
		res += n;
		if (res > offset)
			write(1, buffer, 1);
	}
}

void	ft_tail(int argc, char **argv)
{
	int char_count;
	int i;

	if (argc < 3)
	{
		return ;
	}
	else if (argc == 3)
	{
		ft_display_stdin(ft_atoi(argv[2]));
		return ;
	}
	if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
	{
		char_count = ft_atoi(argv[2]);
		i = 3;
		while (i < argc)
		{
			if (i != 3 && file_length(argv[i], 0, basename(argv[0])) != -1)
				write(1, "\n", 1);
			process_file(argv[i], (argc > 4), char_count, (i == 3),
					basename(argv[0]));
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	ft_tail(argc, argv);
	return (0);
}
