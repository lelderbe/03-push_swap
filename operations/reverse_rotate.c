/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:40:24 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/12 13:40:25 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_app *e)
{
	t_dlist	*tmp;

	if (e->print)
		ft_putendl_fd("rra", 1);
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
		ft_putendl_fd("rrb", 1);
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
	ft_putendl_fd("rrr", 1);
	e->print = 0;
	rra(e);
	e->print = 0;
	rrb(e);
}
