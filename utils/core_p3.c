/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_p3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:45:58 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 17:46:22 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset(t_app *e)
{
	ft_dlstclear(&e->a, free);
	ft_dlstclear(&e->b, free);
	ft_dlstclear(&e->ops, free);
	e->a = NULL;
	e->b = NULL;
	e->ops = NULL;
	if (!make_stack_copy(e->in, &e->a))
		exit_app(e, 1);
	e->size_a = e->count;
	e->size_b = 0;
	e->size_ops = 0;
}
