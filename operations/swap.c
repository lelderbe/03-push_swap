#include "push_swap.h"

void	sa(t_app *e)
{
	t_dlist	*tmp;

	ft_putendl_fd("sa", 1);
	if (ft_dlstsize(e->a) < 2)
		return ;
	tmp = e->a;
	e->a = e->a->next;
	tmp->next = e->a->next;
	tmp->prev = e->a;
	if (tmp->next)
		tmp->next->prev = tmp;
	e->a->next = tmp;
	e->a->prev = NULL;
}

void	sb(t_app *e)
{
	t_dlist	*tmp;

	ft_putendl_fd("sb", 1);
	if (ft_dlstsize(e->b) < 2)
		return ;
	tmp = e->b;
	e->b = e->b->next;
	tmp->next = e->b->next;
	tmp->prev = e->b;
	if (tmp->next)
		tmp->next->prev = tmp;
	e->b->next = tmp;
	e->b->prev = NULL;
}
