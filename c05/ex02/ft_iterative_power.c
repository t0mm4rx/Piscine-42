/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:08:19 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/07 16:14:09 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int res;
	int i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	res = nb;
	i = power - 1;
	while (i--)
		res *= nb;
	return (res);
}
