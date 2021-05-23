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
			pb(e);
		recursion_sort_v2(e);
		sorted_insert(e);
	}
}
