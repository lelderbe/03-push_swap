/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:27:15 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 13:17:51 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_biggest_top(t_app *e, t_dlist *lst)
{
	int	pos;

	pos = get_max_value_pos(lst);
	rotate(e, lst, pos);
}

void	move_smallest_top(t_app *e, t_dlist *lst)
{
	int	pos;

	pos = get_min_value_pos(lst);
	rotate(e, lst, pos);
}

void	move_smallest_to_b(t_app *e)
{
	move_smallest_top(e, e->a);
	pb(e);
}

void	move_all_from_b_to_a(t_app *e)
{
	while (size(e->b) > 0)
		pa(e);
}

void	move_element(t_app *e, t_push elem)
{
	if (elem.cost <= 0)
	{
		ft_putendl_fd("Error: ELEM <= 0 !!!", 2);
		return ;
	}
	while (elem.rr--)
		rr(e);
	while (elem.ra--)
		ra(e);
	while (elem.rb--)
		rb(e);
	while (elem.rrr--)
		rrr(e);
	while (elem.rra--)
		rra(e);
	while (elem.rrb--)
		rrb(e);
	if (elem.pa)
		pa(e);
	else
		pb(e);
}
