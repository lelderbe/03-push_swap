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

static void	move_smallest_to_b(t_app *e)
{
	move_smallest_top(e, e->a);
	pb(e);
}

void	move_all_from_b_back(t_app *e)
{
	while (size(e->b) > 0)
		pa(e);
}

void	sort_insertion(t_app *e)
{
	while (!sorted(e->a) || size(e->b) > 0)
	{
		if (sorted(e->a))
			move_all_from_b_back(e);
		else if (size(e->a) > 3)
			move_smallest_to_b(e);
		else
			sort3(e);
	}
}
