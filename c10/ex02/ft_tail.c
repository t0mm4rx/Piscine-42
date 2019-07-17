/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 00:19:24 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/17 01:59:23 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_header(char *file)
{
	ft_putstr(1, "==> ");
	ft_putstr(1, file);
	ft_putstr(1, " <==\n");
}

int		file_length(char *file)
{
	int		fd;
	int		res;
	int		n;
	char	buffer[1];

	res = 0;
	if ((fd = open(file, 0)) == -1)
	{
		ft_putstr(2, "ft_tail: ");
		ft_putstr(2, file);
		ft_putstr(2, ": No such file or directory");
		return (-1);
	}
	while ((n = read(fd, buffer, 1)) > 0)
		res += n;
	return (res);
}

void	process_file(char *file, int does_display_header, int char_count)
{
	int		fd;
	char	buffer[1];
	int		n;
	int		res;
	int		offset;

	res = 0;
	offset = file_length(file) - char_count;
	fd = open(file, 0);
	if (does_display_header)
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

	if (argc < 4)
	{
		ft_putstr(2, "File name missing.\n");
		return ;
	}
	char_count = ft_atoi(argv[2]);
	i = 3;
	while (i < argc)
	{
		process_file(argv[i++], (argc > 4), char_count);
		if (i != argc && (argc > 4))
			write(1, "\n", 1);
	}
}

int		main(int argc, char **argv)
{
	ft_tail(argc, argv);
	return (0);
}
