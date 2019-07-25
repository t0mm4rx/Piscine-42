/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:18:08 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/12 13:28:27 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	long i;

	if (nb == 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb <= 0)
		return (0);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int i;

	if (ft_is_prime(nb))
		return (nb);
	i = 1;
	while (!ft_is_prime(nb + i))
		i++;
	return (nb + i);
}

#include <stdio.h>
int	main(void)
{
	printf("%d", ft_find_next_prime(-2143647));
	return (0);
}
