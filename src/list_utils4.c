/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:16:58 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/13 17:31:37 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node *sorted_list (node *lst)
{
	node	*sorted;
	int		val;

	sorted = init_list();
	val = get_min(lst);
	push_back(sorted, val);
	while (len_list(sorted) < len_list(lst))
	{
		val = get_value_around(lst, ABOVE, val);
		push_back(sorted, val);
	}
	return (sorted);
}
