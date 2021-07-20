/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:10:23 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 20:34:49 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init(t_app **e, int count)
{
	(void)count;
	*e = malloc(sizeof(**e));
	if (!*e)
		return (FAIL);
	ft_bzero(*e, sizeof(**e));
	(*e)->print = 1;
	return (OK);
}

void	test(t_app *e)
{
	insertion_sort(e);
	ft_putstr_fd("insertion v1 : ", STDOUT_FILENO);
	ft_putnbr_fd(e->size_ops, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	reset(e);
	insertion_sort_v3(e);
	ft_putstr_fd("insertion v3 : ", STDOUT_FILENO);
	ft_putnbr_fd(e->size_ops, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	reset(e);
	greater_sort(e);
	ft_putstr_fd("     greater : ", STDOUT_FILENO);
	ft_putnbr_fd(e->size_ops, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	reset(e);
	radix_sort(e);
	ft_putstr_fd("       radix : ", STDOUT_FILENO);
	ft_putnbr_fd(e->size_ops, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}

int	main(int argc, char *argv[])
{
	t_app	*e;

	if (!init(&e, argc) || !parse_args(e, argv + 1))
		exit_app(e, 1);
	if (!e->a || sorted(e->a))
		exit_app(e, 0);
	if (PR_STACKS)
		print_stacks(e);
	if (size(e->a) == 2)
		sort2(e);
	else if (size(e->a) == 3)
		sort3(e);
	else if (size(e->a) < 2500)
		insertion_sort_v3(e);
	else
		radix_sort(e);
	if (PR_STACKS)
		print_stacks(e);
	if (PR_OPS)
		print_operations(e);
	exit_app(e, 0);
}
