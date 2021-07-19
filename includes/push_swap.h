/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:05:45 by cclaude           #+#    #+#             */
/*   Updated: 2021/07/19 14:55:24 by cclaude          ###   ########.fr       */
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

typedef struct s_node
{
	int					data;
	struct s_node		*prev;
	struct s_node		*next;
}		t_node;

int		get_stack (t_node *stack, int ac, char **av);

t_node	*insert_algorithm (t_node *astack);

void	do_instruction (int op, t_node *astack, t_node *bstack, t_node *ins);

void	push (t_node *from, t_node *to);
void	swap (t_node *stack);
void	rotate (t_node *stack);
void	rrotate (t_node *stack);
void	condense_instructions (t_node *instructions, int rotation);

t_node	*init_list (void);
t_node	*dup_list (t_node *lst);
t_node	*push_back (t_node *lst, int val);
void	pop_t_node (t_node *lst, t_node *nd);
void	free_list (t_node *lst);

int		is_empty (t_node *lst);
int		is_sorted (t_node *lst);
int		is_rsorted (t_node *lst);
int		is_in (t_node *lst, int val);
int		list_len (t_node *lst);

int		list_index_of (t_node *lst, int val);
int		list_value_at (t_node *lst, int index);
int		list_value_around (t_node *lst, int mode, int value);
int		list_max (t_node *lst);
int		list_min (t_node *lst);

t_node	*sorted_list (t_node *lst);
int		list_count (t_node *lst, int value);
int		list_count_from (t_node *lst, t_node *start, int value);
int		list_dist_to (t_node *lst, int val, int *rot);

int		abs (int n);

#endif
