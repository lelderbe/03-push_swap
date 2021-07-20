/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 12:33:54 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 13:44:23 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_sorted(t_app *e)
{
	int	i;

	i = 0;
	while (i < e->count)
	{
		ft_putnbr_fd(e->sorted[i], STDOUT_FILENO);
		ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	ft_putendl_fd("", STDOUT_FILENO);
}

static void	print_stack(t_dlist *lst)
{
	while (lst)
	{
		ft_putnbr_fd(*(int *)lst->content, STDOUT_FILENO);
		ft_putstr_fd(" ", STDOUT_FILENO);
		lst = lst->next;
	}
	ft_putendl_fd("", STDOUT_FILENO);
}

void	print_stacks(t_app *e)
{
	ft_putstr_fd("a: ", STDOUT_FILENO);
	print_stack(e->a);
	ft_putstr_fd("b: ", STDOUT_FILENO);
	print_stack(e->b);
}

void	print_operations(t_app *e)
{
	const char	*op[] = {"pa", "pb", "sa", "sb", "ss", "ra", \
							"rb", "rr", "rra", "rrb", "rrr"};
	t_dlist		*lst;

	lst = e->ops;
	while (lst)
	{
		ft_putendl_fd((char *)op[*(int *)lst->content], STDOUT_FILENO);
		lst = lst->next;
	}
}
