#include "push_swap.h"

void	pa(t_app *e)
{
	t_dlist	*tmp;

	ft_putendl_fd("pa", 1);
	if (!e->b)
		return ;
	tmp = e->b;
	e->b = e->b->next;
	if (e->b)
		e->b->prev = NULL;
	tmp->next = e->a;
	if (e->a)
		e->a->prev = tmp;
	e->a = tmp;
	e->a->prev = NULL;
}

void	pb(t_app *e)
{
	t_dlist	*tmp;

	ft_putendl_fd("pb", 1);
	if (!e->a)
		return ;
	tmp = e->a;
	e->a = e->a->next;
	if (e->a)
		e->a->prev = NULL;
	tmp->next = e->b;
	if (e->b)
		e->b->prev = tmp;
	e->b = tmp;
	e->b->prev = NULL;
}
