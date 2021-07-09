/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:28:42 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/09 17:04:25 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push (node *from, node *to)
{
	node	*pushed;
	node	*top_f;
	node	*top_t;

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
}

void swap (node *stack)
{
	node	*first;
	node	*second;
	node	*third;

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

void rotate (node *stack)
{
	node	*first;
	node	*second;
	node	*last;

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

void rrotate (node *stack)
{
	node	*first;
	node	*last;
	node	*sec_last;

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

void do_instruction (int op, node *astack, node *bstack, node *instructions)
{
	push_back(instructions, op);
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
