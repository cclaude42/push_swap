/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:39:33 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/17 00:45:19 by cclaude          ###   ########.fr       */
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

int is_rsorted (node *lst)
{
	node	*nd;

	nd = lst->next;
	while (nd != lst && nd->next != lst && nd->data > nd->next->data)
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

int len_list (node *lst)
{
	return (lst->data);
}
