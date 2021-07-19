#include "push_swap.h"

void	move_biggest_top(t_app *e, t_dlist *lst)
{
	int pos;

	pos = get_max_value_pos(lst);
	rotate(e, lst, pos);
}

void	move_smallest_top(t_app *e, t_dlist *lst)
{
	int pos;

	pos = get_min_value_pos(lst);
	rotate(e, lst, pos);
}

void	move_smallest_to_b(t_app *e)
{
	move_smallest_top(e, e->a);
	pb(e);
}

void	move_all_from_b_to_a(t_app *e)
{
	while (size(e->b) > 0)
		pa(e);
}

void	move_element(t_app *e, t_push elem)
{
	//print_stacks(e);
	if (elem.cost <= 0)
	{
		printf("Error: ELEM <= 0 !!!\n");
		return ;
	}
	while (elem.rr--)
		rr(e);
	while (elem.ra--)
		ra(e);
	while (elem.rb--)
		rb(e);
	while (elem.rrr--)
		rrr(e);
	while (elem.rra--)
		rra(e);
	while (elem.rrb--)
		rrb(e);
	if (elem.pa)
		pa(e);
	else
		pb(e);
	//print_stacks(e);
}
