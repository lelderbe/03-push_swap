/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:33:12 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 16:29:01 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	too_big_in_this_pos(t_app *e, int value, int pos)
{
	if ((value - pos) * 100 / e->count > 40)
		return (OK);
	return (FAIL);
}

static void	look_b(t_app *e, int prev, int next)
{
	int	diff;
	int	i;
	int	pos;

	diff = next - prev;
	if (next - prev == 1 || size(e->b) == 0)
		return ;
	i = 1;
	while (i < diff)
	{
		pos = get_value_pos(e->b, prev + i);
		if (pos != -1)
		{
			rotate(e, e->b, pos);
			pa(e);
			ra(e);
		}
		i++;
	}
}

static void	check_curr_gt_prev(t_app *e, int *pos, int prev)
{
	int	curr;
	int	next;

	curr = get(e->a, 0);
	next = get(e->a, 1);
	if (curr < next)
		ra(e);
	else if (next > prev)
	{
		sa(e);
		look_b(e, prev, get(e->a, 0));
		ra(e);
	}
	else if (next > get(e->a, size(e->a) - 2))
	{
		sa(e);
		*pos = *pos - 1;
	}
	else
		ra(e);
}

static void	split(t_app *e)
{
	int	pos;
	int	prev;
	int	curr;

	ra(e);
	pos = 0;
	while (pos < e->count - 1)
	{
		prev = get(e->a, size(e->a) - 1);
		curr = get(e->a, 0);
		if (too_big_in_this_pos(e, curr, pos))
			pb(e);
		else if (curr > prev)
			check_curr_gt_prev(e, &pos, prev);
		else if (curr > get(e->a, size(e->a) - 2))
		{
			rra(e);
			sa(e);
			ra(e);
			pos--;
		}
		else
			pb(e);
		pos++;
	}
}

void	greater_sort(t_app *e)
{
	t_push	elem;

	move_smallest_top(e, e->a);
	split(e);
	while (size(e->b))
	{
		elem = get_best_elem_from_b_to_a(e);
		move_element(e, elem);
	}
	move_smallest_top(e, e->a);
}
