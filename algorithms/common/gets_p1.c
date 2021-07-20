/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets_p1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:33:57 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 13:33:59 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value_pos(t_dlist *lst)
{
	int	value;
	int	pos;
	int	i;

	value = *(int *)lst->content;
	pos = 0;
	lst = lst->next;
	i = 1;
	while (lst)
	{
		if (*(int *)lst->content < value)
		{
			value = *(int *)lst->content;
			pos = i;
		}
		lst = lst->next;
		i++;
	}
	return (pos);
}

int	get_max_value_pos(t_dlist *lst)
{
	int	value;
	int	pos;
	int	i;

	value = *(int *)lst->content;
	pos = 0;
	lst = lst->next;
	i = 1;
	while (lst)
	{
		if (*(int *)lst->content > value)
		{
			value = *(int *)lst->content;
			pos = i;
		}
		lst = lst->next;
		i++;
	}
	return (pos);
}

t_push	get_best_elem_from_b_to_a(t_app *e)
{
	int		pos_a;
	int		pos_b;
	t_push	elem;
	t_push	best;

	best = (t_push){0};
	pos_b = 0;
	while (pos_b < size(e->b))
	{
		elem = (t_push){0};
		elem.pa = 1;
		pos_a = get_asc_insert_pos(e->a, get(e->b, pos_b));
		calc_cost(&elem, rotate_value(e->a, pos_a), rotate_value(e->b, pos_b));
		if (best.cost == 0 || elem.cost < best.cost)
			best = elem;
		pos_b++;
	}
	return (best);
}

t_push	get_best_elem_from_a_to_b(t_app *e)
{
	int		pos_a;
	int		pos_b;
	t_push	elem;
	t_push	best;

	best = (t_push){0};
	pos_a = 0;
	while (pos_a < size(e->a))
	{
		elem = (t_push){0};
		elem.pb = 1;
		pos_b = get_desc_insert_pos(e->b, get(e->a, pos_a));
		calc_cost(&elem, rotate_value(e->a, pos_a), rotate_value(e->b, pos_b));
		if (best.cost == 0 || elem.cost < best.cost)
			best = elem;
		pos_a++;
	}
	return (best);
}

t_push	get_best_elem_from_a_to_b_pack(t_app *e, int pack_n, int pack_size)
{
	int		pos_a;
	t_push	elem;
	t_push	best;
	int		i;

	best = (t_push){0};
	i = 0;
	while (i < pack_size)
	{
		elem = (t_push){0};
		elem.pb = 1;
		pos_a = get_value_pos(e->a, pack_n * pack_size + i);
		if (pos_a != -1)
		{
			calc_cost(&elem, rotate_value(e->a, pos_a), 0);
			if (best.cost == 0 || elem.cost < best.cost)
				best = elem;
		}
		i++;
	}
	return (best);
}
