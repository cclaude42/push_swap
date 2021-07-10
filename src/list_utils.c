/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:16:57 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/09 17:17:55 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node *init_list (void)
{
	node	*nil_node;

	nil_node = malloc(sizeof(node));
	if (nil_node)
	{
		nil_node->next = nil_node;
		nil_node->prev = nil_node;
	}
	return (nil_node);
}

node *dup_list (node *lst)
{
	node	*current;
	node	*new_lst;
	node	*new_node;

	current = lst->next;
	new_lst = init_list();
	while (new_lst && current != lst)
	{
		new_node = push_back(new_lst, current->data);
		if (new_node == NULL)
		{
			free_list(new_lst);
			return (NULL);
		}
		current = current->next;
	}
	return (new_lst);
}

node *push_back (node *lst, int val)
{
	node	*new_node;

	new_node = malloc(sizeof(node));
	if (new_node)
	{
		new_node->data = val;
		new_node->prev = lst->prev;
		new_node->next = lst;
		lst->prev->next = new_node;
		lst->prev = new_node;
	}
	return (new_node);
}

void free_list (node *lst)
{
	node	*current;
	node	*next;

	if (lst == NULL)
		return ;
	current = lst->next;
	next = current->next;
	while (current != lst)
	{
		free(current);
		current = next;
		next = next->next;
	}
	free(lst);
}

int len_list (node *lst)
{
	node	*current;
	int		i;

	if (lst == NULL)
		return (-1);
	current = lst->next;
	i = 0;
	while (current != lst)
	{
		current = current->next;
		i++;
	}
	return (i);
}