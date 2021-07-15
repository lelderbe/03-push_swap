/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:44:50 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/15 15:28:53 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_app *e, t_dlist *lst, int pos)
{
	int	op;

	op = RA;
	if (lst == e->b)
		op = RB;
	if (pos > size(lst) / 2)
	{
		op = RRA;
		if (lst == e->b)
			op = RRB;
		pos = size(lst) - pos;
	}
	while (pos > 0)
	{
		if (op == RA)
			ra(e);
		else if (op == RB)
			rb(e);
		else if (op == RRA)
			rra(e);
		else
			rrb(e);
		pos--;
	}
}
/*
void	rotate_a(t_app *e, int pos)
{
	int	op;

	op = RA;
	if (pos > size(e->a) / 2)
	{
		op = RRA;
		pos = size(e->a) - pos;
	}
	while (pos > 0)
	{
		if (op == RA)
			ra(e);
		else
			rra(e);
		pos--;
	}
}

void	rotate_b(t_app *e, int pos)
{
	int	op;

	op = RB;
	if (pos > size(e->b) / 2)
	{
		op = RRB;
		pos = size(e->b) - pos;
	}
	while (pos > 0)
	{
		if (op == RB)
			rb(e);
		else
			rrb(e);
		pos--;
	}
}
*/
void	move_smallest_top(t_app *e, t_dlist *lst)
{
	int	pos;

	pos = get_min_index(lst);
	rotate(e, lst, pos);
	/*
	if (lst == e->a)
		rotate_a(e, pos);
	else
		rotate_b(e, pos);
	*/
}

/*
int	calc_rrr(t_app *e, int pos_a, int pos_b)
{
	pos_a = size(e->a) - pos_a;
	pos_b = size(e->b) - pos_b;
	if (pos_a < pos_b)
		return (pos_a);
	return (pos_b);
}

int	calc_rr(t_app *e, int pos_a, int pos_b)
{
	if (pos_a < pos_b)
		return (pos_a);
	return (pos_b);
}
*/
