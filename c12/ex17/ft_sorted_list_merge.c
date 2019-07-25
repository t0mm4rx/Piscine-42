/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:06:14 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/21 19:19:59 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap4(t_list **el1, t_list **el2)
{
	void *tmp;

	tmp = (*el1)->data;
	(*el1)->data = (*el2)->data;
	(*el2)->data = tmp;
}

void	ft_list_sort4(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	i = 1;
	if (!(*begin_list) || !(*begin_list)->next)
		return ;
	while (i)
	{
		i = 0;
		tmp1 = *begin_list;
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (cmp(tmp1->data, tmp2->data) > 0)
			{
				ft_swap4(&tmp1, &tmp2);
				i = 1;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
}

void	ft_list_merge2(t_list **begin_list1, t_list *begin_list2)
{
	t_list *list;

	if (!(*begin_list1))
	{
		*begin_list1 = begin_list2;
		return ;
	}
	list = *begin_list1;
	while (list->next)
	{
		list = list->next;
	}
	list->next = begin_list2;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	ft_list_merge2(begin_list1, begin_list2);
	ft_list_sort4(begin_list1, cmp);
}
