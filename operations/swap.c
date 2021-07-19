/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:40:38 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 14:30:23 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_app *e)
{
	t_dlist	*tmp;

	if (e->print)
	{
		add(&e->ops, SA);
		e->size_ops++;
	}
	if (ft_dlstsize(e->a) < 2)
		return ;
	tmp = e->a;
	e->a = e->a->next;
	tmp->next = e->a->next;
	tmp->prev = e->a;
	if (tmp->next)
		tmp->next->prev = tmp;
	e->a->next = tmp;
	e->a->prev = NULL;
	e->print = 1;
}

void	sb(t_app *e)
{
	t_dlist	*tmp;

	if (e->print)
	{
		add(&e->ops, SB);
		e->size_ops++;
	}
	if (ft_dlstsize(e->b) < 2)
		return ;
	tmp = e->b;
	e->b = e->b->next;
	tmp->next = e->b->next;
	tmp->prev = e->b;
	if (tmp->next)
		tmp->next->prev = tmp;
	e->b->next = tmp;
	e->b->prev = NULL;
	e->print = 1;
}

void	ss(t_app *e)
{
	add(&e->ops, SS);
	e->size_ops++;
	e->print = 0;
	sa(e);
	e->print = 0;
	sb(e);
	e->print = 1;
}
