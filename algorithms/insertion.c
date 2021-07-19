/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:06:23 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 14:24:37 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_insertion(t_app *e)
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
			break;
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

	//print_stacks(e);
	i = 0;
	while (i < e->count)
	{
		//if (size(e->a) == 3)
		if (e->size_a == 3)
		{
			sort3(e);
			break;
		}
		elem = get_best_elem_from_a_to_b_pack(e, i / pack_size, pack_size);
		//printf("elem to move: cost: %d, ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", elem.cost, elem.ra, elem.rb, elem.rr, elem.rra, elem.rrb, elem.rrr);
		move_element(e, elem);
		i++;
	}
	//print_stacks(e);
	//while (size(e->b))
	while (e->size_b)
	{
		elem = get_best_elem_from_b_to_a(e);
		//printf("elem to move: cost: %d, ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", elem.cost, elem.ra, elem.rb, elem.rr, elem.rra, elem.rrb, elem.rrr);
		move_element(e, elem);
	}
	move_smallest_top(e, e->a);
	//print_stacks(e);
}

void	insertion_sort_v3(t_app *e)
{
	int	pack_size;
	int	step;
	int best;
	int	best_size;

	best_size = 0;
	step = 10;
	pack_size = e->count / 10;
	if (!pack_size)
	{
		pack_size = e->count;
		best_size = pack_size;
	}
	while (pack_size < e->count - e->count / 10)
	{
		insertion_sort_v3_alg(e, pack_size);
		printf("best_size: %d, best: %d, pack_size: %d, ops: %d\n", best_size, best, pack_size, e->size_ops);
		if (!best_size || best > e->size_ops)
		{
			best_size = pack_size;
			best = e->size_ops;
		}
		reset(e);
		pack_size = pack_size + step;
	}
	insertion_sort_v3_alg(e, best_size);
}
