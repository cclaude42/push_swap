/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:02:34 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/17 14:30:12 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_instructions (node *instructions, char *moves, char *targets)
{
	node	*nd;
	char	res[5];
	int		i;

	nd = instructions->next;
	while (nd != instructions)
	{
		i = 0;
		if (nd->data >= R2)
			res[i++] = 'r';
		res[i++] = moves[nd->data / 10 - 1];
		res[i++] = targets[nd->data % 10 - 1];
		res[i++] = '\n';
		write(1, res, i);
		nd = nd->next;
	}
}

void do_instruction (int op, node *astack, node *bstack, node *instructions)
{
	if (op == PA || op == PB)
	{
		condense_instructions(instructions, R);
		condense_instructions(instructions, R2);
	}
	push_back(instructions, op);
	if (op == PA)
		push(bstack, astack);
	if (op == PB)
		push(astack, bstack);
	if (op == SA || op == SS)
		swap(astack);
	if (op == SB || op == SS)
		swap(bstack);
	if (op == RA || op == RR)
		rotate(astack);
	if (op == RB || op == RR)
		rotate(bstack);
	if (op == RRA || op == RRR)
		rrotate(astack);
	if (op == RRB || op == RRR)
		rrotate(bstack);
}

int main (int ac, char **av)
{
	node	*stack;
	node	*sol;

	stack = init_list();
	if (stack && get_stack(stack, ac - 1, av + 1))
	{
		sol = insert_algorithm(stack);
		print_instructions(sol, "sprr", "absr");
		free_list(sol);
		free_list(stack);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
