/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:39:50 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/12 13:40:07 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorted_insert(t_app *e)
{
	if (!e->a || *(int *)e->a->content > *(int *)e->b->content)
	{
		pa(e);
#ifdef PRINT
			print_stacks(e);
#endif
	}
	else
	{
		pb(e);
#ifdef PRINT
			print_stacks(e);
#endif
		sb(e);
#ifdef PRINT
			print_stacks(e);
#endif
		sorted_insert(e);
		pa(e);
#ifdef PRINT
			print_stacks(e);
#endif
	}
}

void	recursion_sort(t_app *e)
{
	if (e->a)
	{
		pb(e);
#ifdef PRINT
			print_stacks(e);
#endif
		recursion_sort(e);
		sorted_insert(e);
	}
}

void	recursion_sort_v2(t_app *e)
{
	if (e->a)
	{
		if (e->b && *(int *)e->b->content > *(int *)e->a->content)
		{
			pb(e);
#ifdef PRINT
			print_stacks(e);
#endif
			sb(e);
#ifdef PRINT
			print_stacks(e);
#endif
		}
		else
		{
			pb(e);
#ifdef PRINT
			print_stacks(e);
#endif
		}
		recursion_sort_v2(e);
		sorted_insert(e);
	}
}
