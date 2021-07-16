/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:26:10 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/16 23:53:47 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_index_of (node *lst, int val)
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

int get_value_at (node *lst, int index)
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

int get_value_around (node *lst, int mode, int value)
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

void print_list (node *lst)
{
	node *current = lst->next;
	fprintf(stderr, "=== lst is : ===\n");
	for (int i = 1 ; current != lst ; current = current->next)
		fprintf(stderr, "%d: %d\n", i++, current->data);
	fprintf(stderr, "================\n");
}
