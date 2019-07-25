/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 07:54:46 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/19 08:02:25 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int		main(int argc, char **argv)
{
	int		option;
	char	*str;

	if (argc < 2)
	{
		return (0);
	}
	option = ft_atoi(argv[2], 0);
	if (option == -1)
	{
		ft_illegal_offset(argv);
		return (0);
	}
	if (argc == 3)
	{
		ft_putstr(get_stdin(option));
	}
	else
		str = ft_write(argv, argc, option);
	return (0);
}
