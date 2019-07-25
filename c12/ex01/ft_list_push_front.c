/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:51:59 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/19 09:32:04 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **list, void *data)
{
	t_list *elem;

	elem = ft_create_elem(data);
	if (*list)
		elem->next = *list;
	*list = elem;
}
