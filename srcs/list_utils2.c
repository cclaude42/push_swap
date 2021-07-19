/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:39:33 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/19 14:55:03 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty (t_node *lst)
{
	if (lst == lst->next)
		return (1);
	return (0);
}

int	is_sorted (t_node *lst)
{
	t_node	*nd;

	nd = lst->next;
	while (nd != lst && nd->next != lst && nd->data < nd->next->data)
		nd = nd->next;
	if (nd->next == lst)
		return (1);
	return (0);
}

int	is_rsorted (t_node *lst)
{
	t_node	*nd;

	nd = lst->next;
	while (nd != lst && nd->next != lst && nd->data > nd->next->data)
		nd = nd->next;
	if (nd->next == lst)
		return (1);
	return (0);
}

int	is_in (t_node *lst, int val)
{
	t_node	*nd;

	nd = lst->next;
	while (nd != lst)
	{
		if (nd->data == val)
			return (1);
		nd = nd->next;
	}
	return (0);
}

int	list_len (t_node *lst)
{
	return (lst->data);
}
