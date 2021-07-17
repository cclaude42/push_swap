/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:02:34 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/17 01:29:50 by cclaude          ###   ########.fr       */
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

void condense_instructions (node *instructions, int target)
{
	node	*nd;
	int		acount;
	int		bcount;

	nd = instructions->prev;
	while (nd != instructions && nd->data / 10 * 10 != P)
		nd = nd->prev;
	acount = list_count_from(instructions, nd, target + A);
	bcount = list_count_from(instructions, nd, target + B);
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
			pop_node(instructions, nd->next);
		}
		nd = nd->next;
	}
}

int main (int ac, char **av)
{
	node	*stack;
	node	*sol;

	stack = init_list();
	if (!stack || get_stack(stack, ac - 1, av + 1))
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
