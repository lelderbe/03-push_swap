/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:19:01 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 16:18:40 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <limits.h>

# define APP_NAME	"push_swap"
# define FAIL		0
# define OK			1

# define PR_OPS		0
# define PR_STACKS	1

# define PA			0
# define PB			1
# define SA			2
# define SB			3
# define SS			4
# define RA			5
# define RB			6
# define RR			7
# define RRA		8
# define RRB		9
# define RRR		10

typedef struct s_app {
	int			count;
	t_dlist		*in;
	t_dlist		*a;
	t_dlist		*b;
	int			size_a;
	int			size_b;
	int			print;
	int			*sorted;
	t_dlist		*ops;
	int			size_ops;
}				t_app;

/*	element for move  */
typedef struct s_push {
	int			cost;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}				t_push;

/*	main functions  */

int		exit_app(t_app *e, int code);
void	reset(t_app *e);
int		parse_args(t_app *e, char **argv);

/*	print utils  */

void	print_sorted(t_app *e);
void	print_stacks(t_app *e);
void	print_operations(t_app *e);

/*	core utils  */

int		protected_atoi(const char *str, int *value);
int		get_sorted_index(t_app *e, int value);
int		min(int a, int b);
int		make_stack_copy(t_dlist *original, t_dlist **copy);
int		has_digit(const char *s);
void	free_split(char **s);
void	array_bubble_sort(int *arr, int count);

/*	list utils  */

int		add(t_dlist **lst, int value);
int		exist(t_dlist *lst, int value);
int		size(t_dlist *lst);
int		sorted(t_dlist *lst);

/*	common get operations  */

int		get(t_dlist *lst, int index);
int		get_value_pos(t_dlist *lst, int value);
int		get_asc_insert_pos(t_dlist *lst, int value);
int		get_desc_insert_pos(t_dlist *lst, int value);
int		get_min_value_pos(t_dlist *lst);
int		get_max_value_pos(t_dlist *lst);
t_push	get_best_elem_from_a_to_b(t_app *e);
t_push	get_best_elem_from_b_to_a(t_app *e);
t_push	get_best_elem_from_a_to_b_pack(t_app *e, int pack_n, int pack_size);

/*	common move operations  */

void	move_all_from_b_to_a(t_app *e);
void	move_smallest_to_b(t_app *e);
void	move_biggest_top(t_app *e, t_dlist *lst);
void	move_smallest_top(t_app *e, t_dlist *lst);
void	move_element(t_app *e, t_push elem);
void	calc_cost(t_push *e, int rva, int rvb);
int		rotate_value(t_dlist *lst, int pos);
void	rotate(t_app *e, t_dlist *lst, int pos);
void	insert_from_b(t_app *e);

/*	algorithms  */

void	sort2(t_app *e);
void	sort3(t_app *e);
void	recursion_sort(t_app *e);
void	recursion_sort_v2(t_app *e);
void	recursion_sort_v3(t_app *e);
void	sort_insertion(t_app *e);
void	insertion_sort_v2(t_app *e);
void	insertion_sort_v3(t_app *e);
void	sort_greater(t_app *e);
void	sort_radix(t_app *e);

/*	stack operations  */

void	pa(t_app *e);
void	pb(t_app *e);
void	sa(t_app *e);
void	sb(t_app *e);
void	ss(t_app *e);
void	ra(t_app *e);
void	rb(t_app *e);
void	rr(t_app *e);
void	rra(t_app *e);
void	rrb(t_app *e);
void	rrr(t_app *e);

#endif
