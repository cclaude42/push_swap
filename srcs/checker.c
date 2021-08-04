/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:49:56 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 23:07:01 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_instruction (int op, t_node *astack, t_node *bstack, t_node *ins)
{
	(void)ins;
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

int	solve (t_node *astack, t_node *bstack, t_node *instructions)
{
	t_node	*nd;

	nd = instructions->next;
	while (nd != instructions)
	{
		do_instruction(nd->data, astack, bstack, instructions);
		nd = nd->next;
	}
	if (is_sorted(astack) && is_empty(bstack))
		return (1);
	else
		return (0);
}

int	add_instruction (t_node *instructions, char ins[5])
{
	if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == 'a' && ins[3] == '\n')
		push_back(instructions, RRA);
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == 'b' && ins[3] == '\n')
		push_back(instructions, RRB);
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == 'r' && ins[3] == '\n')
		push_back(instructions, RRR);
	else if (ins[0] == 'r' && ins[1] == 'a' && ins[2] == '\n')
		push_back(instructions, RA);
	else if (ins[0] == 'r' && ins[1] == 'b' && ins[2] == '\n')
		push_back(instructions, RB);
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == '\n')
		push_back(instructions, RR);
	else if (ins[0] == 's' && ins[1] == 'a' && ins[2] == '\n')
		push_back(instructions, SA);
	else if (ins[0] == 's' && ins[1] == 'b' && ins[2] == '\n')
		push_back(instructions, SB);
	else if (ins[0] == 's' && ins[1] == 's' && ins[2] == '\n')
		push_back(instructions, SS);
	else if (ins[0] == 'p' && ins[1] == 'a' && ins[2] == '\n')
		push_back(instructions, PA);
	else if (ins[0] == 'p' && ins[1] == 'b' && ins[2] == '\n')
		push_back(instructions, PB);
	else
		return (0);
	return (1);
}

int	get_instructions (t_node *instructions)
{
	char	ins[5];
	char	buf[1];
	int		ret;
	int		i;

	ret = 1;
	i = 0;
	while (read(0, buf, sizeof(buf)) > 0)
	{
		ins[i++] = *buf;
		if (i > 4)
			ret = 0;
		if (*buf == '\n')
		{
			if (add_instruction(instructions, ins) == 0)
				ret = 0;
		}
		if (i > 4 || *buf == '\n')
			i = 0;
	}
	return (ret);
}

int	main (int ac, char **av)
{
	t_node	*astack;
	t_node	*bstack;
	t_node	*instructions;

	astack = init_list();
	bstack = init_list();
	instructions = init_list();
	if (astack && bstack && instructions
		&& get_stack(astack, ac - 1, av + 1) && get_instructions(instructions))
	{
		if (solve(astack, bstack, instructions))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_list(astack);
		free_list(bstack);
		free_list(instructions);
	}
	else if (ac != 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
