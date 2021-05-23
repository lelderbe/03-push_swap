#include "push_swap.h"

void	ra(t_app *e)
{
	t_dlist	*tmp;
	t_dlist	*last;

	if (e->print)
		ft_putendl_fd("ra", 1);
	if (ft_dlstsize(e->a) < 2)
		return ;
	tmp = e->a;
	last = ft_dlstlast(e->a);
	e->a = e->a->next;
	e->a->prev = NULL;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	e->print = 1;
}

void	rb(t_app *e)
{
	t_dlist	*tmp;
	t_dlist	*last;

	if (e->print)
		ft_putendl_fd("rb", 1);
	if (ft_dlstsize(e->b) < 2)
		return ;
	tmp = e->b;
	last = ft_dlstlast(e->b);
	e->b = e->b->next;
	e->b->prev = NULL;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	e->print = 1;
}

void	rr(t_app *e)
{
	ft_putendl_fd("rr", 1);
	e->print = 0;
	ra(e);
	e->print = 0;
	rb(e);
	e->print = 1;
}
