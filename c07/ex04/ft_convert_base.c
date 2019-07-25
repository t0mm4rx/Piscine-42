/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 07:27:51 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/16 00:55:12 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		get_value(char c, char *base);
int		is_space(char c);
int		check_base(char *str);
int		ft_atoi_base(char *str, char *base);

void	ft_putnbr_base(char *res, int nbr, char *base, int *last_n)
{
	int b;

	b = ft_strlen(base);
	if (nbr <= -2147483648)
	{
		res[0] = '-';
		(*last_n)++;
		ft_putnbr_base(res, (-(long int)nbr) / b, base, last_n);
		ft_putnbr_base(res, (-(long int)nbr) % b, base, last_n);
	}
	else if (nbr < 0)
	{
		res[0] = '-';
		(*last_n)++;
		ft_putnbr_base(res, -nbr, base, last_n);
	}
	else if (nbr < b)
	{
		res[(*last_n)++] = base[nbr];
	}
	else
	{
		ft_putnbr_base(res, nbr / b, base, last_n);
		ft_putnbr_base(res, nbr % b, base, last_n);
	}
}

int		count_digits(int nb, char *base)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb - (nb % ft_strlen(base));
		nb = nb / ft_strlen(base);
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*res;
	int		last_n;

	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	n = ft_atoi_base(nbr, base_from);
	res = malloc(sizeof(char) * (count_digits(n, base_to) + 1));
	last_n = 0;
	ft_putnbr_base(res, n, base_to, &last_n);
	res[count_digits(n, base_to)] = '\0';
	return (res);
}
