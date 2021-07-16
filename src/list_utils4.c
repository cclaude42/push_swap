/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:16:58 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/17 00:10:29 by cclaude          ###   ########.fr       */
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

int list_count (node *lst, int value)
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

int list_count_from (node *lst, node *start, int value)
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

int list_dist_to (node *lst, int val, int *rot)
{
	int	n;

	n = get_index_of(lst, val);
	if (n > len_list(lst) / 2)
	{
		*rot = R2;
		n = len_list(lst) - n;
	}
	else
		*rot = R;
	return (n);
}

// int list_rot_to (node *lst, int val, int pos_rot, int neg_rot)
// {
// 	if (get_index_of(lst, val) > len_list(lst) / 2)
// 		return (neg_rot);
// 	else
// 		return (pos_rot);
// }
