/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:44:50 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 14:24:35 by lelderbe         ###   ########.fr       */
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

void	insert_from_b(t_app *e)
{
	int	pos;

	while (size(e->b) > 0)
	{
		pos = get_insert_pos(e->a, get(e->b, 0));
		rotate(e, e->a, pos);
		pa(e);
	}
}

void	move_smallest_top(t_app *e, t_dlist *lst)
{
	int	pos;

	pos = get_min_index(lst);
	rotate(e, lst, pos);
}
