/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:37:18 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/09 17:34:23 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_to_top (int a_or_b, int val, node *stack, node *instructions)
{
	int	n;
	int	op;

	n = get_index(stack, val);
	op = R;
	// printf("Finding n\n");
	if (get_index(stack, val) > len_list(stack) / 2)
	{
		n = len_list(stack) - get_index(stack, val);
		op = R2;
	}
	// printf("Running %d times\n", n);
	while (n-- > 0)
	{
		if (a_or_b == A)
			do_instruction(op + a_or_b, stack, NULL, instructions);
		else
			do_instruction(op + a_or_b, NULL, stack, instructions);
		// printf("%d to go\n", n);
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
		// printf("Emptying a\n");
		if (get_max(astack) == astack->next->data)
			do_instruction(RA, astack, bstack, instructions);
		else
			do_instruction(PB, astack, bstack, instructions);
		// print_list(astack);
		// print_list(bstack);
	}
	while (!is_empty(bstack))
	{
		// printf("Filling a back up\n");
		get_to_top(B, get_max(bstack), bstack, instructions);
		do_instruction(PA, astack, bstack, instructions);
		// print_list(astack);
		// print_list(bstack);
	}
	// print_list(astack);
	// print_list(bstack);
	return (instructions);
}
