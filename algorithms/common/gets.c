#include "push_swap.h"

t_push	get_best_elem_from_b_to_a(t_app *e)
{
	int		pos_a;
	int		pos_b;
	t_push	elem;
	t_push	best;

	best = (t_push){0};
	pos_b = 0;
	while (pos_b < size(e->b))
	{
		elem = (t_push){0};
		elem.pa = 1;
		pos_a = get_asc_insert_pos(e->a, get(e->b, pos_b));
		//printf("for value: %d insert position is: %d\n", get(lst1, pos), pos_2);
		calc_cost(&elem, rotate_value(e->a, pos_a), rotate_value(e->b, pos_b));
		//printf("pos: %d, curr: cost: %d, ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", pos, curr.cost, curr.ra, curr.rb, curr.rr, curr.rra, curr.rrb, curr.rrr);
		if (best.cost == 0 || elem.cost < best.cost)
			best = elem;
		pos_b++;
	}
	return (best);
}

t_push	get_best_elem_from_a_to_b(t_app *e)
{
	int		pos_a;
	int		pos_b;
	t_push	elem;
	t_push	best;

	best = (t_push){0};
	pos_a = 0;
	while (pos_a < size(e->a))
	{
		elem = (t_push){0};
		elem.pb = 1;
		//pos_b = get_insert_pos(e->b, get(e->a, pos_a));
		pos_b = get_desc_insert_pos(e->b, get(e->a, pos_a));
		//printf("for value: %d insert position is: %d\n", get(lst1, pos), pos_2);
		(void)pos_b;
		//calc_cost(&elem, rotate_value(e->a, pos_a), 0);
		calc_cost(&elem, rotate_value(e->a, pos_a), rotate_value(e->b, pos_b));
		//printf("pos: %d, curr: cost: %d, ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", pos, curr.cost, curr.ra, curr.rb, curr.rr, curr.rra, curr.rrb, curr.rrr);
		if (best.cost == 0 || elem.cost < best.cost)
			best = elem;
		pos_a++;
	}
	return (best);
}

t_push	get_best_elem_from_a_to_b_pack(t_app *e, int pack_n, int pack_size)
{
	int		pos_a;
	int		pos_b;
	t_push	elem;
	t_push	best;
	int		i;

	best = (t_push){0};
	i = 0;
	while (i < pack_size)
	{
		elem = (t_push){0};
		elem.pb = 1;
		//printf("for value: %d\n", part * 20 + i);
		//printf("curr: cost: %d, ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", curr.cost, curr.ra, curr.rb, curr.rr, curr.rra, curr.rrb, curr.rrr);
		pos_a = get_value_pos(e->a, pack_n * pack_size + i);
		if (pos_a != -1)
		{
			pos_b = get_desc_insert_pos(e->b, pack_n * pack_size + i);
			(void)pos_b;
			calc_cost(&elem, rotate_value(e->a, pos_a), 0);
			//calc_cost(&elem, rotate_value(e->a, pos_a), rotate_value(e->b, pos_b));
			if (best.cost == 0 || elem.cost < best.cost)
				best = elem;
		}
		i++;
	}
	return (best);
}
