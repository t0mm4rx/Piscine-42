/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 12:26:51 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/06 20:24:26 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_digit(int n)
{
	n += 48;
	write(1, &n, 1);
}

void	ft_putnbr(int n)
{
	if (n <= -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
		return ;
	}
	if (n < 10)
	{
		ft_print_digit(n);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_print_digit(n % 10);
	}
}
