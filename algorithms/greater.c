/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:33:12 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/14 15:33:28 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_smallest_top(t_app *e)
{
	int	index;
	int	op;

	index = get_min_index(e->a);
	op = RA;
	if (index > size(e->a) / 2)
	{
		op = RRA;
		index = size(e->a) - index;
	}
	while (index)
	{
		if (op == RA)
			ra(e);
		else
			rra(e);
		index--;
	}
}
/*
static void	push_b_not_sorted(t_app *e)
{
	t_dlist
}
*/
static int	too_big_in_this_pos(t_app *e, int value, int pos)
{
	//printf("==ordered: for value: %d position is: %d. percent: %d\n", value, get_arr_index(e, value), (get_arr_index(e, value) - pos) * 100 / e->count);
	if ((get_arr_index(e, value) - pos) * 100 / e->count > 30)
	{
		return (OK);
	}
	return (FAIL);
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
	while (pos < e->count - 1 && size(e->a) > 0)
	{
		curr = get(e->a, 0);
		next = get(e->a, 1);
		if (too_big_in_this_pos(e, curr, pos))
		{
			//printf("%d is too big in position %d, do pb\n", curr, pos);
			pb(e);
		}
		else
		{
			if (curr > prev)
			{
				if (curr > next && next > prev)
				{
					//printf("%d > %d and %d > %d, do sa and ra\n", curr, prev, curr, next);
					sa(e);
					prev = next;
				}
				else
				{
					//printf("%d > %d but %d < %d, do ra\n", curr, prev, curr, next);
					prev = curr;
				}
				ra(e);
			}
			else
			{
				//printf("%d < %d, do pb\n", curr, prev);
				pb(e);
			}
		}
		pos++;
		//print_stacks(e);
	}
	//ra(e);
	//print_stacks(e);
}

static void	insert_from_b(t_app *e)
{
	int	pos;

	while (size(e->b) > 0)
	{
		pos = get_index(e->a, get(e->b, 0));
		//printf("for value: %d position is: %d\n", get(e->b, 0), pos);
		while (pos > 0)
		{
			ra(e);
			pos--;
		}
		pa(e);
		//print_stacks(e);
	}
}

void	sort_greater(t_app *e)
{
	//printf("------- 1: move smallest to the top\n");
	move_smallest_top(e);
	//print_stacks(e);
	//printf("------- 2: split stack\n");
	split(e);
	//printf("------- 3: move b to a\n");
	insert_from_b(e);
	//printf("------- 4: move smallest to the top\n");
	move_smallest_top(e);
}


