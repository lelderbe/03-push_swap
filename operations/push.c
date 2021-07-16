/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:40:16 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 14:31:04 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_app *e)
{
	t_dlist	*tmp;

	add(&e->ops, PA);
	if (!e->b)
		return ;
	tmp = e->b;
	e->b = e->b->next;
	if (e->b)
		e->b->prev = NULL;
	tmp->next = e->a;
	if (e->a)
		e->a->prev = tmp;
	e->a = tmp;
	e->a->prev = NULL;
}

void	pb(t_app *e)
{
	t_dlist	*tmp;

	add(&e->ops, PB);
	if (!e->a)
		return ;
	tmp = e->a;
	e->a = e->a->next;
	if (e->a)
		e->a->prev = NULL;
	tmp->next = e->b;
	if (e->b)
		e->b->prev = tmp;
	e->b = tmp;
	e->b->prev = NULL;
}
