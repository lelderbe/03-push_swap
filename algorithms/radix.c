/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:00:20 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 13:00:22 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_radix(t_app *e)
{
	int	i;
	int	mask;

	mask = 1;
	while (!sorted(e->a))
	{
		i = 0;
		while (i < e->count)
		{
			if (!(get(e->a, 0) & mask))
				pb(e);
			else
				ra(e);
			i++;
		}
		move_all_from_b_to_a(e);
		mask = mask << 1;
	}
}
