/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:16:58 by cclaude           #+#    #+#             */
/*   Updated: 2021/09/08 20:01:18 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*sorted_list(t_node *lst)
{
	t_node	*sorted;
	int		val;

	sorted = init_list();
	val = list_min(lst);
	push_back(sorted, val);
	while (list_len(sorted) < list_len(lst))
	{
		val = list_value_around(lst, ABOVE, val);
		push_back(sorted, val);
	}
	return (sorted);
}

int	list_count(t_node *lst, int value)
{
	t_node	*nd;
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

int	list_count_from(t_node *lst, t_node *start, int value)
{
	t_node	*nd;
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

int	list_dist_to(t_node *lst, int val, int *rot)
{
	int	n;

	n = list_index_of(lst, val);
	if (n > list_len(lst) / 2)
	{
		*rot = R2;
		n = list_len(lst) - n;
	}
	else
		*rot = R;
	return (n);
}
