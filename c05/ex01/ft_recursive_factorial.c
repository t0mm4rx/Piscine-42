/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 00:02:43 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/07 00:03:11 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb == 2)
		return (2);
	if (nb == 1 || nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	return (ft_recursive_factorial(nb - 1) * nb);
}
