/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 07:53:35 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/19 08:02:02 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(char *str, int j)
{
	int	i;
	int	res;

	res = 0;
	i = j;
	if (!ft_is_numeric(str[i]))
		return (-1);
	while (ft_is_numeric(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}
