/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:33:12 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/15 15:56:05 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	too_big_in_this_pos(t_app *e, int value, int pos)
{
#ifdef PRINT
	printf("[ ] for value: %d position is: [%d]. percent: %d\n", value, get_arr_index(e, value), (get_arr_index(e, value) - pos) * 100 / e->count);
#endif
	(void)e;
	(void)pos;
	if ((get_arr_index(e, value) - pos) * 100 / e->count > 30)
	//if (value > 70)
	{
		return (OK);
	}
	return (FAIL);
}

static void	move_value_from_b(t_app *e, int pos)
{
	//rotate_b(e, pos);
	rotate(e, e->b, pos);
	pa(e);
}

static void	look_b(t_app *e, int prev, int next)
{
	int	diff;
	int	i;
	int	pos;

	diff = next - prev;
	if (next - prev == 1 || size(e->b) == 0)
		return ;
	i = 1;
	while (i < diff)
	{
		pos = get_index(e->b, prev + i);
#ifdef PRINT
		printf("check b for: %d, found at pos: %d, do pa and ra\n", prev + i, pos);
#endif
		if (pos != -1)
		{
			move_value_from_b(e, pos);
			ra(e);
		}
		i++;
	}
}

static void	move_to_b(t_app *e)
{
	int	pos;

	pos = get_insert_pos(e->b, get(e->a, 0));
#ifdef PRINT
	printf("move to b - for value: %d position is: %d\n", get(e->a, 0), pos);
#endif
	//rotate_a(e, pos);
	rotate(e, e->b, pos);
	pb(e);
#ifdef PRINT
	print_stacks(e);
#endif
}

static void	split(t_app *e)
{
	int	pos;
	int	prev;
	int	curr;
	int	next;

	prev = get(e->a, 0);
	ra(e);
	pos = 0;
	while (pos < e->count - 1)
	{
#ifdef PRINT
		printf("********* check pos: %d **********\n", pos);
		print_stacks(e);
#endif
		prev = get(e->a, size(e->a) - 1);
		curr = get(e->a, 0);
		next = get(e->a, 1);
		if (too_big_in_this_pos(e, curr, pos))
		{
#ifdef PRINT
			printf("%d is too big in position %d, do pb\n", curr, pos);
#endif
			move_to_b(e);
		}
		else
		{
			if (curr > prev)
			{
				if (curr > next)
				{
					if (next > prev)
					{
#ifdef PRINT
						printf("%d > %d and %d > %d and %d > %d, do sa and ra\n", curr, prev, curr, next, next, prev);
#endif
						sa(e);
						//look_b(e, prev, next);
						//prev = next;
						//prev = get(e->a, 0);
						look_b(e, prev, get(e->a, 0));
						//prev = get(e->a, 0);
						ra(e);
					}
					else
					{
						if (next > get(e->a, size(e->a) - 2))
						{
							// do sa and pos - 1
#ifdef PRINT
							printf("%d > %d and %d > %d but %d < %d, do sa and repeat this pos again\n", curr, prev, curr, next, next, get(e->a, size(e->a) - 2));
#endif
							sa(e);
							pos--;
						}
						else
						{
#ifdef PRINT
							printf("do sa doesn't help\n");
							ra(e);
#endif
						}
					}
				}
				else
				{
#ifdef PRINT
					printf("%d > %d but %d < %d, do ra\n", curr, prev, curr, next);
					ra(e);
#endif
					//prev = curr;
				}
				//look_b(e, prev, get(e->a, 0));
				//prev = get(e->a, 0);
				//ra(e);
			}
			else
			{
				if (curr > get(e->a, size(e->a) - 2))
				{
#ifdef PRINT
					printf("%d < %d but %d > %d (prev - 1), do rra + sa + ra\n", curr, prev, curr, get(e->a, size(e->a) - 2));
#endif
					// change with prev
					rra(e);
					sa(e);
					ra(e);
					prev = get(e->a, size(e->a) - 1);
				}
				else
				{
#ifdef PRINT
					printf("%d < %d and < prev - 1, do pb\n", curr, prev);
#endif
					move_to_b(e);
					//pb(e);
				}
			}
		}
		pos++;
#ifdef PRINT
		print_stacks(e);
#endif
	}
}

static void	insert_from_b(t_app *e)
{
	int	pos;

	while (size(e->b) > 0)
	{
		pos = get_insert_pos(e->a, get(e->b, 0));
#ifdef PRINT
		printf("for value: %d position is: %d\n", get(e->b, 0), pos);
#endif
		//rotate_a(e, pos);
		rotate(e, e->a, pos);
		/*
		while (pos > 0)
		{
			ra(e);
			pos--;
		}
		*/
		pa(e);
#ifdef PRINT
		print_stacks(e);
#endif
	}
}

void	sort_greater(t_app *e)
{
#ifdef PRINT
	printf("------- 1: move smallest to the top\n");
#endif
	move_smallest_top(e, e->a);
#ifdef PRINT
	print_stacks(e);
	printf("------- 2: split stack\n");
#endif
	split(e);
#ifdef PRINT
	printf("------- 3: move b to a\n");
#endif
	insert_from_b(e);
#ifdef PRINT
	printf("------- 4: move smallest to the top\n");
#endif
	move_smallest_top(e, e->a);
}


