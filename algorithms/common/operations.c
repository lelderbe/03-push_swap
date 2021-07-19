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

void	calc_cost(t_push *e, int rva, int rvb)
{
	if (rva < 0)
		e->rra = -rva;
	else
		e->ra = rva;
	if (rvb < 0)
		e->rrb = -rvb;
	else
		e->rb = rvb;
	e->rr = min(e->ra, e->rb);
	e->ra = e->ra - e->rr;
	e->rb = e->rb - e->rr;
	e->rrr = min(e->rra, e->rrb);
	e->rra = e->rra - e->rrr;
	e->rrb = e->rrb - e->rrr;
	e->cost = e->pa + e->pb + e->ra + e->rb + e->rr + e->rra + e->rrb + e->rrr;
}

void	insert_from_b(t_app *e)
{
	int	pos;

	while (size(e->b) > 0)
	{
		pos = get_asc_insert_pos(e->a, get(e->b, 0));
		rotate(e, e->a, pos);
		pa(e);
	}
}
