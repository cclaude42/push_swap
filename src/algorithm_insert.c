/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 21:03:15 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/17 01:09:17 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int test_target (node *astack, node *bstack, int atarget, int btarget)
{
	int	adist;
	int	bdist;
	int	arot;
	int	brot;

	adist = list_dist_to(astack, atarget, &arot);
	bdist = list_dist_to(bstack, btarget, &brot);
	if (arot == brot)
	{
		if (adist > bdist)
			bdist = 0;
		else
			adist = 0;
	}
	return (adist + bdist);
}

int find_best_target (node *astack, node *bstack)
{
	int	best_target;
	int	best_nmoves;
	int	target;
	int	nmoves;
	int	i;

	i = 0;
	best_target = -1;
	best_nmoves = INT_MAX;
	while (abs(i) < len_list(bstack) / 2 + 1 && abs(i) < best_nmoves)
	{
		target = get_value_at(bstack, (bstack->data + i) % bstack->data);
		nmoves = test_target(astack, bstack,
			get_value_around(astack, ABOVE, target), target);
		if (nmoves < best_nmoves)
		{
			best_target = target;
			best_nmoves = nmoves;
		}
		i = -i;
		if (i >= 0)
			i++;
	}
	return (best_target);
}

void refill_astack (node *astack, node *bstack, node *instructions)
{
	int	target;
	int	n;
	int	rotation;

	while (!is_empty(bstack))
	{
		target = find_best_target(astack, bstack);
		n = list_dist_to(bstack, target, &rotation);
		while (n-- > 0)
			do_instruction(rotation + B, astack, bstack, instructions);
		target = get_value_around(astack, ABOVE, target);
		n = list_dist_to(astack, target, &rotation);
		while (n-- > 0)
			do_instruction(rotation + A, astack, bstack, instructions);
		condense_instructions(instructions);
		do_instruction(PA, astack, bstack, instructions);
	}
}

void fill_bstack (node *astack, node *bstack, node *instructions)
{
	node	*nd;
	int		median;

	nd = sorted_list(astack);
	median = get_value_at(nd, len_list(nd) / 2);
	free_list(nd);
	while (len_list(astack) > 3)
	{
		nd = astack->next;
		if (nd->data == get_min(astack) || nd->data == get_max(astack))
			do_instruction(RA, astack, bstack, instructions);
		else
		{
			condense_instructions(instructions);
			do_instruction(PB, astack, bstack, instructions);
			if (nd->data < median)
				do_instruction(RB, astack, bstack, instructions);
		}
	}
}

node *insert_algorithm (node *astack)
{
	node	*instructions;
	node	*bstack;

	instructions = init_list();
	bstack = init_list();
	fill_bstack(astack, bstack, instructions);
	if (get_value_at(astack, (get_index_of(astack, get_max(astack)) + 1) % 3)
		!= get_min(astack))
		do_instruction(SA, astack, NULL, instructions);
	if (get_value_at(astack, 0) == get_min(astack))
		do_instruction(RA, astack, NULL, instructions);
	refill_astack(astack, bstack, instructions);
	while (get_value_at(astack, 0) != get_min(astack))
	{
		if (get_index_of(astack, get_min(astack)) > len_list(astack) / 2)
			do_instruction(RRA, astack, bstack, instructions);
		else
			do_instruction(RA, astack, bstack, instructions);
	}
	return (instructions);
}
