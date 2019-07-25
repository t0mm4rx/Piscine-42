/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:38:37 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/17 18:57:40 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int a;
	int b;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (argv[2][0] == '-')
		process(a, -b, &add);
	else if (argv[2][0] == '+')
		process(a, b, &add);
	else if (argv[2][0] == '*')
		process(a, b, &mult);
	else if (argv[2][0] == '/')
		process(a, b, &div);
	else if (argv[2][0] == '%')
		process(a, b, &mod);
	else
		write(1, "0\n", 2);
	return (0);
}
