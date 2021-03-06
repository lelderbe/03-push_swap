/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:39:50 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 13:04:00 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorted_insert(t_app *e)
{
	if (!e->a || *(int *)e->a->content > *(int *)e->b->content)
	{
		pa(e);
	}
	else
	{
		pb(e);
		sb(e);
		sorted_insert(e);
		pa(e);
	}
}

static void	sorted_insert_v3(t_app *e)
{
	if (size(e->b) > 1)
	{
		if (get(e->b, 0) < get(e->b, 1))
			sb(e);
	}
	if (!e->a || *(int *)e->a->content > *(int *)e->b->content)
	{
		pa(e);
	}
	else
	{
		pb(e);
		sb(e);
		sorted_insert_v3(e);
		pa(e);
	}
}

void	recursion_sort(t_app *e)
{
	if (e->a)
	{
		pb(e);
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
			sb(e);
		}
		else
		{
			pb(e);
		}
		recursion_sort_v2(e);
		sorted_insert(e);
	}
}

void	recursion_sort_v3(t_app *e)
{
	if (e->a)
	{
		if (e->b && *(int *)e->b->content > *(int *)e->a->content)
		{
			pb(e);
			sb(e);
		}
		else
		{
			pb(e);
		}
		recursion_sort_v3(e);
		sorted_insert_v3(e);
	}
}
