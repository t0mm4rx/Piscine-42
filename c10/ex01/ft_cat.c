/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:43:28 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/18 19:02:12 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>

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

void	ft_display_file(char *file, char *program_name)
{
	int		fd;
	int		n;
	char	buffer[4096];

	fd = open(file, 0);
	if (fd == -1)
	{
		ft_putstr(2, program_name);
		ft_putstr(2, ": ");
		ft_putstr(2, file);
		ft_putstr(2, ": No such file or directory\n");
		return ;
	}
	while ((n = read(fd, buffer, 4096)) > 0)
	{
		write(1, buffer, n);
	}
	close(fd);
}

void	ft_display_stdin(void)
{
	int		n;
	char	buffer[4096];

	while ((n = read(0, buffer, 4096)) > 0)
	{
		write(1, buffer, n);
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			ft_display_file(argv[i++], basename(argv[0]));
		}
	}
	else
		ft_display_stdin();
	return (0);
}
