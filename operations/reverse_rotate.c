/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:40:24 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 14:30:38 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_app *e)
{
	t_dlist	*tmp;

	if (e->print)
	{
		add(&e->ops, RRA);
		e->size_ops++;
	}
	if (ft_dlstsize(e->a) < 2)
		return ;
	tmp = e->a;
	e->a = ft_dlstlast(e->a);
	e->a->prev->next = NULL;
	e->a->prev = NULL;
	e->a->next = tmp;
	tmp->prev = e->a;
	e->print = 1;
}

void	rrb(t_app *e)
{
	t_dlist	*tmp;

	if (e->print)
	{
		add(&e->ops, RRB);
		e->size_ops++;
	}
	if (ft_dlstsize(e->b) < 2)
		return ;
	tmp = e->b;
	e->b = ft_dlstlast(e->b);
	e->b->prev->next = NULL;
	e->b->prev = NULL;
	e->b->next = tmp;
	tmp->prev = e->b;
	e->print = 1;
}

void	rrr(t_app *e)
{
	add(&e->ops, RRR);
	e->size_ops++;
	e->print = 0;
	rra(e);
	e->print = 0;
	rrb(e);
}
