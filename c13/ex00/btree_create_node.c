/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 03:51:52 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/22 09:59:58 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*el;

	if (!(el = malloc(sizeof(t_btree))))
		return (0);
	el->left = 0;
	el->right = 0;
	el->item = item;
	return (el);
}
