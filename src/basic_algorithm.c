/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:37:18 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/14 14:18:59 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_to_top (int a_or_b, int val, node *stack, node *instructions)
{
	int	n;
	int	rotation;

	n = get_index_of(stack, val);
	rotation = R;
	if (n > len_list(stack) / 2)
	{
		n = len_list(stack) - n;
		rotation = R2;
	}
	while (n-- > 0)
	{
		if (a_or_b == A)
			do_instruction(rotation + a_or_b, stack, NULL, instructions);
		else
			do_instruction(rotation + a_or_b, NULL, stack, instructions);
	}
}

node *basic_algorithm (node *astack)
{
	node	*instructions;
	node	*bstack;

	instructions = init_list();
	bstack = init_list();
	while (len_list(astack) > 1)
	{
		if (get_max(astack) == astack->next->data)
			do_instruction(RA, astack, bstack, instructions);
		else
			do_instruction(PB, astack, bstack, instructions);
	}
	while (!is_empty(bstack))
	{
		get_to_top(B, get_max(bstack), bstack, instructions);
		do_instruction(PA, astack, bstack, instructions);
	}
	return (instructions);
}
