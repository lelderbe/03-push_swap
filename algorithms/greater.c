/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:33:12 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 13:42:57 by lelderbe         ###   ########.fr       */
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

	//return ;
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

static void	move_to_b(t_app *e)
{
	//rotate(e, e->b, get_insert_pos(e->b, get(e->a, 0)));
	pb(e);
}

static void	split(t_app *e)
{
	int	pos;
	int	prev;
	int	curr;
	int	next;

	prev = get(e->a, 0);
	ra(e);
	pos = 0;
	while (pos < e->count - 1)
	{
		prev = get(e->a, size(e->a) - 1);
		curr = get(e->a, 0);
		next = get(e->a, 1);
		if (too_big_in_this_pos(e, curr, pos))
			move_to_b(e);
		else if (curr > prev)
		{
			if (curr > next)
			{
				if (next > prev)
				{
					sa(e);
					look_b(e, prev, get(e->a, 0));
					ra(e);
				}
				else
				{
					if (next > get(e->a, size(e->a) - 2))
					{
						sa(e);
						pos--;
					}
					else
					{
						ra(e);
					}
				}
			}
			else
				ra(e);
		}
		else
		{
			if (curr > get(e->a, size(e->a) - 2))
			{
				rra(e);
				sa(e);
				ra(e);
				pos--;
			}
			else
				move_to_b(e);
		}
		pos++;
	}
}

void	sort_greater(t_app *e)
{
	t_push	elem;

	move_smallest_top(e, e->a);
	split(e);
	//insert_from_b(e);
	while (size(e->b))
	{
		elem = get_best_elem_from_b_to_a(e);
		move_element(e, elem);
	}
	move_smallest_top(e, e->a);
}
