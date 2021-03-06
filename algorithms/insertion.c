/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:06:23 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 20:12:22 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_app *e)
{
	while (!sorted(e->a) || size(e->b) > 0)
	{
		if (sorted(e->a))
			move_all_from_b_to_a(e);
		else if (size(e->a) > 3)
			move_smallest_to_b(e);
		else
			sort3(e);
	}
}

void	insertion_sort_v2(t_app *e)
{
	t_push	elem;

	while (!sorted(e->a))
	{
		if (size(e->a) == 3)
		{
			sort3(e);
			break ;
		}
		elem = get_best_elem_from_a_to_b(e);
		move_element(e, elem);
	}
	while (size(e->b))
	{
		elem = get_best_elem_from_b_to_a(e);
		move_element(e, elem);
	}
	move_smallest_top(e, e->a);
}

static void	insertion_sort_v3_alg(t_app *e, int pack_size)
{
	t_push	elem;
	int		i;

	i = 0;
	while (i < e->count)
	{
		if (e->size_a == 3)
		{
			sort3(e);
			break ;
		}
		elem = get_best_elem_from_a_to_b_pack(e, i / pack_size, pack_size);
		move_element(e, elem);
		i++;
	}
	while (e->size_b)
	{
		elem = get_best_elem_from_b_to_a(e);
		move_element(e, elem);
	}
	move_smallest_top(e, e->a);
}

void	insertion_sort_v3(t_app *e)
{
	int	pack_size;
	int	step;
	int	best_ops;
	int	best_pack_size;

	best_pack_size = 0;
	best_ops = 0;
	pack_size = e->count / 3;
	step = e->count / 8;
	if (!pack_size)
		best_pack_size = e->count;
	if (!step)
		step = 1;
	while (pack_size && pack_size < e->count)
	{
		insertion_sort_v3_alg(e, pack_size);
		if (!best_pack_size || best_ops > e->size_ops)
		{
			best_pack_size = pack_size;
			best_ops = e->size_ops;
		}
		reset(e);
		pack_size = pack_size + step;
	}
	insertion_sort_v3_alg(e, best_pack_size);
}
