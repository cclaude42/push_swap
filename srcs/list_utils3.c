/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:26:10 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/17 02:08:12 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int list_index_of (node *lst, int val)
{
	node	*nd;
	int		i;

	nd = lst->next;
	i = 0;
	while (nd != lst && nd->data != val)
	{
		nd = nd->next;
		i++;
	}
	return (i);
}

int list_value_at (node *lst, int index)
{
	node	*nd;
	int		i;

	nd = lst->next;
	i = 0;
	while (i < index)
	{
		nd = nd->next;
		i++;
	}
	return (nd->data);
}

int list_value_around (node *lst, int mode, int value)
{
	node	*nd;
	int		under;
	int		above;

	nd = lst->next;
	under = INT_MIN;
	above = INT_MAX;
	while (nd != lst)
	{
		if (nd->data < value && nd->data > under)
			under = nd->data;
		if (nd->data > value && nd->data < above)
			above = nd->data;
		nd = nd->next;
	}
	if (mode == ABOVE)
		return (above);
	else
		return (under);
}

int list_max (node *lst)
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

int list_min (node *lst)
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