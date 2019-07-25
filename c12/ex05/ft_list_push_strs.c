/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 23:14:44 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/21 18:13:28 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front2(t_list **list, void *data)
{
	t_list *elem;

	elem = ft_create_elem(data);
	if (*list)
		elem->next = *list;
	*list = elem;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*begin;

	begin = 0;
	i = 0;
	while (i < size)
		ft_list_push_front2(&begin, strs[i++]);
	return (begin);
}
