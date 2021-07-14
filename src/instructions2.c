/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:39:11 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/14 15:47:28 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void condense_instructions (node *instructions, int target)
{
	node	*nd;
	int		acount;
	int		bcount;

	nd = instructions->prev;
	while (nd != instructions && nd->data / 10 * 10 != P)
		nd = nd->prev;
	acount = count_from_list(instructions, nd, target + A);
	bcount = count_from_list(instructions, nd, target + B);
	if (acount > bcount)
		acount = bcount;
	else
		bcount = acount;
	while (nd != instructions)
	{
		if (nd->data == target + A && acount-- > 0)
			nd->data = target + XR;
		else if (nd->data == target + B && bcount-- > 0 )
		{
			nd = nd->prev;
			pop_node(nd->next);
		}
		nd = nd->next;
	}
}
