#include "push_swap.h"

void	sort_radix(t_app *e)
{
	int		i;
	int		mask;

	print_stacks(e);
	mask = 1;
	while (!sorted(e->a))
	{
		i = 0;
		printf("i: %d, mask: %d\n", i, mask);
		while (i < e->count)
		{
			if (!(get(e->a, 0) & mask))
				pb(e);
			else
				ra(e);
			i++;
		}
		print_stacks(e);
		move_all_from_b_back(e);
		mask = mask << 1;
		print_stacks(e);
	}
}
