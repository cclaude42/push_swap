/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:01:58 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/08 18:17:46 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_num (char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		str++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

long get_val (char *str)
{
	long	n;
	int		i;
	int		s;

	i = 0;
	n = 0;
	s = 1;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i])
		n = n * 10 + str[i++] - '0';
	if (n > 2147483647 || n < -2147483648)
		return (2147483648);
	return (n * s);
}

int is_in (node *stack, int val)
{
	node	*current;

	current = stack->next;
	while (current != stack)
	{
		if (current->data == val)
			return (1);
		current = current->next;
	}
	return (0);
}

int get_stack (node *stack, int ac, char **av)
{
	node	*new_node;
	int		i;

	if (ac == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		new_node = add_node(stack);
		if (new_node == NULL || is_num(av[i]) == 0 ||
			get_val(av[i]) == 2147483648 || is_in(stack, get_val(av[i])) == 1)
		{
			free_list(stack);
			return (0);
		}
		new_node->data = get_val(av[i++]);
	}
	return (1);
}
