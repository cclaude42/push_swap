/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:02:34 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/10 17:17:52 by cclaude          ###   ########.fr       */
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
		// printf("num is %d\n", nd->data);
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

node *try_algorithm (node *stack, int algo)
{
	node	*instructions;

	instructions = NULL;
	// printf("Running algorithm %d\n", algo);
	if (algo == BASIC)
		instructions = basic_algorithm(stack);
	// printf("Ran algorithm %d\n", algo);

	return (instructions);
}

node *sort_stack (node *stack)
{
	node	*copy;
	node	*instructions;
	node	*best;
	int		algo;

	algo = 1;
	best = NULL;
	while (algo <= NB_ALGORITHMS)
	{
		copy = dup_list(stack);
		instructions = try_algorithm(copy, algo++);
		if (best == NULL || len_list(best) > len_list(instructions))
		{
			free_list(best);
			best = instructions;
		}
		else
			free_list(instructions);
	}
	return (instructions);
}

int main (int ac, char **av)
{
	node	*stack;
	node	*sol;

	stack = init_list();
	if (!stack || get_stack(stack, ac - 1, av + 1))
	{
		sol = sort_stack(stack);
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
