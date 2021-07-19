#include "push_swap.h"

int		rotate_value(t_dlist *lst, int pos)
{
	int	len;

	if (pos < 0)
		return (0);
	len = size(lst);
	if (pos > len / 2)
		return (pos - len);
	return (pos);
}

void	rotate(t_app *e, t_dlist *lst, int pos)
{
	int	op;

	op = RA;
	if (lst == e->b)
		op = RB;
	if (pos > size(lst) / 2)
	{
		op = RRA;
		if (lst == e->b)
			op = RRB;
		pos = size(lst) - pos;
	}
	while (pos > 0)
	{
		if (op == RA)
			ra(e);
		else if (op == RB)
			rb(e);
		else if (op == RRA)
			rra(e);
		else
			rrb(e);
		pos--;
	}
}
