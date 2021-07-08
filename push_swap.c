/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:02:34 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/08 18:32:14 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list (node *lst)
{
	node *current = lst->next;
	printf("=== lst is : ===\n");
	for (int i = 1 ; current != lst ; current = current->next)
		printf("%d: %d\n", i++, current->data);
	printf("================\n");
}

node *try_algorithm (node *stack, int algo)
{
	node	*instructions;

	if (algo == BASIC)
		instructions = basic_algorithm(stack);

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
		print_instructions(sol);
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
