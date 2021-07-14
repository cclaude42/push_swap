/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:16:58 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/14 15:18:46 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node *sorted_list (node *lst)
{
	node	*sorted;
	int		val;

	sorted = init_list();
	val = get_min(lst);
	push_back(sorted, val);
	while (len_list(sorted) < len_list(lst))
	{
		val = get_value_around(lst, ABOVE, val);
		push_back(sorted, val);
	}
	return (sorted);
}

int count_list (node *lst, int value)
{
	node	*nd;
	int		count;

	nd = lst->next;
	count = 0;
	while (nd != lst)
	{
		if (nd->data == value)
			count++;
		nd = nd->next;
	}
	return (count);
}

int count_from_list (node *lst, node *start, int value)
{
	node	*nd;
	int		count;

	nd = start;
	count = 0;
	while (nd != lst)
	{
		if (nd->data == value)
			count++;
		nd = nd->next;
	}
	return (count);
}
