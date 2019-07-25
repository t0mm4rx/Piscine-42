/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:55:02 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/21 19:19:44 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front3(t_list **list, void *data)
{
	t_list *elem;

	elem = ft_create_elem(data);
	if (*list)
		elem->next = *list;
	*list = elem;
}

void	ft_swap2(t_list **el1, t_list **el2)
{
	void *tmp;

	tmp = (*el1)->data;
	(*el1)->data = (*el2)->data;
	(*el2)->data = tmp;
}

void	ft_list_sort2(t_list **begin_list, int (*cmp)())
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
				ft_swap2(&tmp1, &tmp2);
				i = 1;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_front3(begin_list, data);
	ft_list_sort2(begin_list, cmp);
}
