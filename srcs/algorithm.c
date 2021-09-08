/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 21:03:15 by cclaude           #+#    #+#             */
/*   Updated: 2021/09/08 20:00:17 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_target(t_node *astack, t_node *bstack, int atarget, int btarget)
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

int	find_best_target(t_node *astack, t_node *bstack)
{
	int	best_target;
	int	best_nmoves;
	int	target;
	int	nmoves;
	int	i;

	i = 0;
	best_target = -1;
	best_nmoves = INT_MAX;
	while (abs(i) < list_len(bstack) / 2 + 1 && abs(i) < best_nmoves)
	{
		target = list_value_at(bstack, (bstack->data + i) % bstack->data);
		nmoves = test_target(astack, bstack,
				list_value_around(astack, ABOVE, target), target);
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

void	refill_astack(t_node *astack, t_node *bstack, t_node *instructions)
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
		target = list_value_around(astack, ABOVE, target);
		n = list_dist_to(astack, target, &rotation);
		while (n-- > 0)
			do_instruction(rotation + A, astack, bstack, instructions);
		do_instruction(PA, astack, bstack, instructions);
	}
}

void	fill_bstack(t_node *astack, t_node *bstack, t_node *instructions)
{
	t_node	*nd;
	int		median;

	nd = sorted_list(astack);
	median = list_value_at(nd, list_len(nd) / 2);
	free_list(nd);
	while (list_len(astack) > 3)
	{
		nd = astack->next;
		if (nd->data == list_min(astack) || nd->data == list_max(astack))
			do_instruction(RA, astack, bstack, instructions);
		else
		{
			do_instruction(PB, astack, bstack, instructions);
			if (nd->data < median)
				do_instruction(RB, astack, bstack, instructions);
		}
	}
}

t_node	*insert_algorithm(t_node *astack)
{
	t_node	*instructions;
	t_node	*bstack;

	instructions = init_list();
	bstack = init_list();
	fill_bstack(astack, bstack, instructions);
	if (list_value_at(astack, (list_index_of(astack, list_max(astack)) + 1) % 3)
		!= list_min(astack))
		do_instruction(SA, astack, NULL, instructions);
	if (list_value_at(astack, 0) == list_min(astack))
		do_instruction(RA, astack, NULL, instructions);
	refill_astack(astack, bstack, instructions);
	while (list_value_at(astack, 0) != list_min(astack))
	{
		if (list_index_of(astack, list_min(astack)) > list_len(astack) / 2)
			do_instruction(RRA, astack, bstack, instructions);
		else
			do_instruction(RA, astack, bstack, instructions);
	}
	free_list(bstack);
	return (instructions);
}
