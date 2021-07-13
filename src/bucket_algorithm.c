/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:21:09 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/12 19:08:33 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node *get_bucket_limits (node *stack, int n)
{
	node	*limits;
	int		len;
	int		i;
	int		val;

	limits = init_list();
	len = len_list(stack);
	i = 1;
	while (i <= n)
	{
		val = get_value_at(stack, i * len / n - 1);
		push_back(limits, val);
		i++;
	}
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
	target = get_max(stack);
	if (insert < get_max(stack))
		target = get_value_around(stack, ABOVE, insert);
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
			do_instruction(PB, astack, bstack, instructions);
		}
		do_instruction(rotation + A, astack, bstack, instructions);
	}
}

node *bucket_algorithm (node *astack)
{
	node	*instructions;
	node	*bstack;
	node	*limits;

	instructions = init_list();
	bstack = init_list();
	limits = get_bucket_limits(astack, 11);
	while (!is_empty(limits))
	{
		sort_bucket(limits->next->data, astack, bstack, instructions);
		pop_node(limits->next);
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
