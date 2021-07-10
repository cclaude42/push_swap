/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:26:10 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/09 17:34:05 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_index (node *lst, int val)
{
	node	*nd;
	int		i;

	nd = lst->next;
	i = 0;
	while (nd != lst && nd->data != val)
	{
		nd = nd->next;
		i++;
	}
	return (i);
}

void print_list (node *lst)
{
	node *current = lst->next;
	printf("=== lst is : ===\n");
	for (int i = 1 ; current != lst ; current = current->next)
		printf("%d: %d\n", i++, current->data);
	printf("================\n");
}
