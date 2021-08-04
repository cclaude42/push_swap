/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:02:34 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 23:00:37 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instructions (t_node *instructions, char *moves, char *targets)
{
	t_node	*nd;
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

void	do_instruction (int op, t_node *astack, t_node *bstack, t_node *ins)
{
	if (op == PA || op == PB)
	{
		condense_instructions(ins, R);
		condense_instructions(ins, R2);
	}
	push_back(ins, op);
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

int	main (int ac, char **av)
{
	t_node	*stack;
	t_node	*sol;

	stack = init_list();
	if (ac == 1)
		return (0);
	else if (stack && get_stack(stack, ac - 1, av + 1))
	{
		if (is_sorted(stack))
			return (0);
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
