/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:29:21 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/19 11:29:23 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert_elem(t_list **l, t_list *elem,
		int (*cmp)())
{
	if (!*l || cmp(elem->data, (*l)->data) <= 0)
	{
		elem->next = *l;
		*l = elem;
	}
	else
		ft_sorted_list_insert_elem(&(*l)->next, elem, cmp);
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	if (!begin_list2)
		return ;
	ft_sorted_list_merge(begin_list1, begin_list2->next, cmp);
	ft_sorted_list_insert_elem(begin_list1, begin_list2, cmp);
}
