/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:01:36 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/16 14:36:11 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		ft_strlen(char *str)
{
	char *s;

	s = str;
	while (*str)
		str++;
	return (str - s);
}

void	ft_putstr(int chan, char *str)
{
	write(chan, str, ft_strlen(str));
}

void	ft_display_file(char *file)
{
	int		fd;
	int		n;
	char	buffer[4096];

	fd = open(file, 0);
	if (fd == -1)
	{
		ft_putstr(2, "Cannot read file.\n");
		return ;
	}
	while ((n = read(fd, buffer, 4096)) > 0)
	{
		write(1, buffer, n);
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
	{
		ft_putstr(2, "File name missing.\n");
		return (0);
	}
	else if (argc > 2)
	{
		ft_putstr(2, "Too many arguments.\n");
		return (0);
	}
	ft_display_file(argv[1]);
	return (0);
}
