/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:05:45 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/09 17:20:57 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define BASIC 1

# define NB_ALGORITHMS 1

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

# define S   10
# define P   20
# define R   30
# define R2  40
# define A   1
# define B   2

typedef struct			s_node
{
	int					data;
	struct s_node *		prev;
	struct s_node *		next;
}						node;

int get_stack (node *stack, int ac, char **av);

node *basic_algorithm (node *astack);

void do_instruction (int op, node *astack, node *bstack, node *instructions);

node *init_list (void);
node *dup_list (node *lst);
node *push_back (node *lst, int val);
void free_list (node *lst);
int len_list (node *lst);

int is_empty (node *lst);
int is_sorted (node *lst);
int is_in (node *lst, int val);
int get_max (node *lst);
int get_min (node *lst);

int get_index (node *lst, int val);
void print_list (node *lst);

# endif
