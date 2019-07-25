/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:42:18 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/03 16:09:17 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int buffer[size];
	int i;
	int j;

	i = 0;
	while (i++ < size)
	{
		buffer[size - i] = *(tab + i - 1);
	}
	j = 0;
	while (j++ < size)
	{
		tab[j - 1] = buffer[j - 1];
	}
}
