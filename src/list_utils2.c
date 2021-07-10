/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:39:33 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/09 14:55:42 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_empty (node *lst)
{
	if (lst == lst->next)
		return (1);
	return (0);
}

int is_sorted (node *lst)
{
	node	*nd;

	nd = lst->next;
	while (nd != lst && nd->next != lst && nd->data < nd->next->data)
		nd = nd->next;
	if (nd->next == lst)
		return (1);
	return (0);
}

int is_in (node *lst, int val)
{
	node	*nd;

	nd = lst->next;
	while (nd != lst)
	{
		if (nd->data == val)
			return (1);
		nd = nd->next;
	}
	return (0);
}

int get_max (node *lst)
{
	node	*nd;
	int		max;

	nd = lst->next;
	max = INT_MIN;
	while (nd != lst)
	{
		if (nd->data > max)
			max = nd->data;
		nd = nd->next;
	}
	return (max);
}

int get_min (node *lst)
{
	node	*nd;
	int		min;

	nd = lst->next;
	min = INT_MAX;
	while (nd != lst)
	{
		if (nd->data < min)
			min = nd->data;
		nd = nd->next;
	}
	return (min);
}
