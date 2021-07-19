/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:35:09 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 14:09:32 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_app *e)
{
	if (get(e->a, 0) > get(e->a, 1))
		sa(e);
}

void	sort3(t_app *e)
{
	int	pos;

	pos = get_max_value_pos(e->a);
	if (pos == 0)
		ra(e);
	else if (pos == 1)
		rra(e);
	sort2(e);
}
