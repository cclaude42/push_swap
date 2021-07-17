/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:05:45 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/17 02:08:06 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

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
# define XS  3
# define XR  4

# define UNDER 0
# define ABOVE 1

typedef struct			s_node
{
	int					data;
	struct s_node *		prev;
	struct s_node *		next;
}						node;

int get_stack (node *stack, int ac, char **av);

node *insert_algorithm (node *astack);

void do_instruction (int op, node *astack, node *bstack, node *instructions);

void condense_instructions (node *instructions, int rotation);

node *init_list (void);
node *dup_list (node *lst);
node *push_back (node *lst, int val);
void pop_node (node *lst, node *nd);
void free_list (node *lst);

int is_empty (node *lst);
int is_sorted (node *lst);
int is_rsorted (node *lst);
int is_in (node *lst, int val);
int list_len (node *lst);

int list_index_of (node *lst, int val);
int list_value_at (node *lst, int index);
int list_value_around (node *lst, int mode, int value);
int list_max (node *lst);
int list_min (node *lst);

node *sorted_list (node *lst);
int list_count (node *lst, int value);
int list_count_from (node *lst, node *start, int value);
int list_dist_to (node *lst, int val, int *rot);

int abs (int n);

# endif
