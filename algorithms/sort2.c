/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:35:09 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/13 17:46:33 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_app *e)
{
	if (get(e->a, 0) > get(e->a, 1))
		sa(e);
}

void	sort3(t_app *e)
{
	int index;
   
	index = max_index(e->a);
	if (index == 2)
	{
		sort2(e);
	}
	else if (index == 0)
	{
		ra(e);
		sort2(e);
	}
	else
	{
		rra(e);
		sort2(e);
	}
}

void	move_smallest_to_b(t_app *e)
{
	int index;

	index = min_index(e->a);
	if (index <= size(e->a) / 2)
	{
		while (index)
		{
			ra(e);
			index = index - 1;
		}
	}
	else
	{
		index = size(e->a) - index;
		while (index)
		{
			rra(e);
			index = index - 1;
		}
	}
	pb(e);
}

void	move_all_from_b_back(t_app *e)
{
	while (size(e->b) > 0)
	{
		pa(e);
	}
}

void	sort_a_lot(t_app *e)
{
	while (!is_sorted(e->a) || size(e->b) > 0)
	{
		if (is_sorted(e->a))
			move_all_from_b_back(e);
		else if (size(e->a) > 3)
			move_smallest_to_b(e);
		else
		{
			sort3(e);
			move_all_from_b_back(e);
		}
	}
}
/*
void	sort_several(t_app *e)
{
	while (!is_sorted(e->a) || size(e->b) > 0)
	{
		if (is_sorted(e->a))
			move_all_from_b_back(e);
		else if (size(e->a) > 3)
			move_smallest_to_b(e);
		else
		{
			sort3(e);
			move_all_from_b_back(e);
		}
	}

}
*/

