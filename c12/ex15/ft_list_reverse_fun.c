/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:17:54 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/21 19:17:07 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size3(t_list *list)
{
	t_list	*current;
	int		i;

	i = 0;
	current = list;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_list	*ft_list_at3(t_list *begin_list, unsigned int nbr)
{
	t_list			*list;
	unsigned int	i;

	i = 0;
	list = begin_list;
	while (i < nbr)
	{
		if (!list)
			return (0);
		list = list->next;
		i++;
	}
	return (list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		l;
	void	*tmp;

	i = 0;
	l = ft_list_size3(begin_list);
	while (i < l / 2)
	{
		tmp = ft_list_at3(begin_list, i)->data;
		ft_list_at3(begin_list, i)->data =
			ft_list_at3(begin_list, l - i - 1)->data;
		ft_list_at3(begin_list, l - i - 1)->data = tmp;
		i++;
	}
}
