/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:51:24 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/12 12:46:55 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_digit(int n)
{
	n += 48;
	write(1, &n, 1);
}

void	ft_putnbr(int n)
{
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

void	ft_show_tab(struct s_stock_str *tab)
{
	int			i;
	t_stock_str	temp;

	i = 0;
	while (((t_stock_str*)tab)[i].str)
	{
		temp = ((t_stock_str*)tab)[i];
		ft_putstr(temp.str);
		ft_putstr("\n");
		ft_putnbr(temp.size);
		ft_putstr("\n");
		ft_putstr(temp.copy);
		ft_putstr("\n");
		i++;
	}
}
