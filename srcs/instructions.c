/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:28:42 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/19 14:55:03 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push (t_node *from, t_node *to)
{
	t_node	*pushed;
	t_node	*top_f;
	t_node	*top_t;

	pushed = from->next;
	top_f = pushed->next;
	top_t = to->next;
	if (pushed != from)
	{
		from->next = top_f;
		top_f->prev = from;
		to->next = pushed;
		top_t->prev = pushed;
		pushed->prev = to;
		pushed->next = top_t;
	}
	from->data--;
	to->data++;
}

void	swap (t_node *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->next;
	second = first->next;
	third = second->next;
	if (first != stack && second != stack)
	{
		stack->next = second;
		second->prev = stack;
		third->prev = first;
		first->next = third;
		first->prev = second;
		second->next = first;
	}
}

void	rotate (t_node *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	first = stack->next;
	second = first->next;
	last = stack->prev;
	if (first != stack && second != stack)
	{
		last->next = first;
		stack->prev = first;
		stack->next = second;
		second->prev = stack;
		first->prev = last;
		first->next = stack;
	}
}

void	rrotate (t_node *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*sec_last;

	first = stack->next;
	last = stack->prev;
	sec_last = last->prev;
	if (last != stack && sec_last != stack)
	{
		stack->next = last;
		first->prev = last;
		sec_last->next = stack;
		stack->prev = sec_last;
		last->prev = stack;
		last->next = first;
	}
}

void	condense_instructions (t_node *instructions, int target)
{
	t_node	*nd;
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
			pop_t_node(instructions, nd->next);
		}
		nd = nd->next;
	}
}
