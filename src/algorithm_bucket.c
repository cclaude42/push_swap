/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_bucket.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:21:09 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/17 00:19:50 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node *get_bucket_limits (node *stack, int n)
{
	node	*sorted;
	node	*limits;
	int		len;
	int		i;
	int		val;

	sorted = sorted_list(stack);
	limits = init_list();
	len = len_list(sorted);
	i = 1;
	while (i <= n)
	{
		val = get_value_at(sorted, i * len / n - 1);
		push_back(limits, val);
		i++;
	}
	free_list(sorted);
	return (limits);
}

int get_rotation (node *stack, int min, int max)
{
	int	n;
	int	rotation;

	n = get_index_of(stack, min);
	if (get_index_of(stack, max) < n)
		n = get_index_of(stack, max);
	rotation = R;
	if (n > len_list(stack) / 2)
		rotation = R2;
	return (rotation);
}

void prepare_insertion (int insert, node *stack, node *instructions)
{
	int	target;
	int	rotation;

	if (len_list(stack) < 2)
		return ;
	if (insert > get_min(stack) && insert < get_max(stack))
		target = get_value_around(stack, UNDER, insert);
	else
		target = get_max(stack);
	rotation = R;
	if (get_index_of(stack, target) > len_list(stack) / 2)
		rotation = R2;
	while (stack->next->data != target)
		do_instruction(rotation + B, NULL, stack, instructions);
}

void sort_bucket (int limit, node *astack, node *bstack, node *instructions)
{
	int	rotation;

	if (is_in(astack, limit))
		rotation = get_rotation(astack, get_min(astack), limit);
	while (!is_empty(astack) && get_min(astack) <= limit)
	{
		if (astack->next->data <= limit)
		{
			prepare_insertion(astack->next->data, bstack, instructions);
			condense_instructions(instructions);
			do_instruction(PB, astack, bstack, instructions);
		}
		else
			do_instruction(rotation + A, astack, bstack, instructions);
	}
}

node *bucket_algorithm (node *astack, int n)
{
	node	*instructions;
	node	*bstack;
	node	*limits;

	instructions = init_list();
	bstack = init_list();
	limits = get_bucket_limits(astack, n);
	while (!is_empty(limits))
	{
		sort_bucket(limits->next->data, astack, bstack, instructions);
		pop_node(limits, limits->next);
	}
	while (bstack->next->data != get_max(bstack))
	{
		if (get_index_of(bstack, get_max(bstack)) > len_list(bstack) / 2)
			do_instruction(RRB, astack, bstack, instructions);
		else
			do_instruction(RB, astack, bstack, instructions);
	}
	while (!is_empty(bstack))
		do_instruction(PA, astack, bstack, instructions);
	return (instructions);
}
