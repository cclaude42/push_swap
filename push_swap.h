/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:05:45 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/08 18:16:39 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define SA  11
# define SB  12
# define SS  13
# define PA  21
# define PB  22
# define RA  31
# define RB  32
# define RR  34
# define RRA 41
# define RRB 42
# define RRR 44

typedef struct			s_node
{
	int					data;
	struct s_node *		prev;
	struct s_node *		next;
}						node;

int get_stack (node *stack, int ac, char **av);
node *init_list (void);
node *dup_list (node *lst);
node *add_node (node *lst);
int len_list (node *lst);
void free_list (node *lst);

# endif
