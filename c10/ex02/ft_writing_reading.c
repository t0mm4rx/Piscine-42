/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing_reading.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 07:55:14 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/19 08:01:09 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

char	*ft_write(char **argv, int argc, int option)
{
	int		i;
	int		fd;
	char	*str;
	int		c_f[2];

	c_f[1] = 0;
	str = malloc((option + 1) * sizeof(char));
	i = ft_init(argv);
	while (i < argc)
	{
		c_f[0] = ft_count(argv, i) - option;
		fd = open(argv[i], O_RDONLY);
		if (!ft_error(fd, argv, i))
		{
			c_f[1] = ft_flag(c_f[1], argv, argc, i);
			ft_display(c_f, str, fd);
		}
		i++;
	}
	return (str);
}

int		ft_count(char **argv, int i)
{
	char	c;
	int		count;
	int		fd;

	count = 0;
	fd = open(argv[i], O_RDONLY);
	if (fd > 0)
	{
		while (read(fd, &c, 1) > 0)
		{
			count++;
		}
		close(fd);
	}
	i++;
	return (count);
}

int		ft_init(char **argv)
{
	if (ft_strlen(argv[1]) >= 3)
		return (2);
	else
		return (3);
}

int		ft_flag(int flag, char **argv, int argc, int i)
{
	if (flag == 1)
		ft_putstr("\n");
	ft_banner(argv, argc, i);
	return (1);
}

void	ft_display(int c_f[2], char *str, int fd)
{
	int	j;

	j = 0;
	while (j < c_f[0] && read(fd, &str, 1) > 0)
		j++;
	j = 0;
	while (read(fd, &str[j], 1) > 0)
		j++;
	close(fd);
	str[j] = 0;
	ft_putstr(str);
}
