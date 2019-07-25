/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 01:48:48 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/18 13:40:49 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(void **p1, void **p2)
{
	void *temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void	ft_sort_string_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i + 1])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				ft_swap((void**)&tab[i], (void**)&tab[j]);
			}
			j++;
		}
		i++;
	}
}
