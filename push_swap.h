/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:19:01 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/15 15:38:20 by lelderbe         ###   ########.fr       */
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

//# define PRINT

typedef struct s_app {
	int			count;
	t_dlist		*a;
	t_dlist		*b;
	int			print;
	int			*sorted;
	t_dlist		*ops;
}				t_app;

int		parse_args(t_app *e, char **argv);
void	print_stacks(t_app *e);
int		protected_atoi(const char *str, int *value);
int		get_arr_index(t_app *e, int value);

int		exist(t_dlist *lst, int value);
int		add(t_dlist **lst, int value);
int		get(t_dlist *lst, int index);
int		get_index(t_dlist *lst, int value);
int		get_gr_index(t_dlist *lst, int value);
int		size(t_dlist *lst);
int		get_min_index(t_dlist *lst);
int		get_max_index(t_dlist *lst);
int		sorted(t_dlist *lst);

void	rotate(t_app *e, t_dlist *lst, int pos);
//void	rotate_a(t_app *e, int pos);
//void	rotate_b(t_app *e, int pos);
void	move_smallest_top(t_app *e, t_dlist *lst);

void	recursion_sort(t_app *e);
void	recursion_sort_v2(t_app *e);
void	sort2(t_app *e);
void	sort3(t_app *e);
void	sort_a_lot(t_app *e);
void	sort_greater(t_app *e);

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
