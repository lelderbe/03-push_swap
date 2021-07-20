/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:10:23 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 16:24:15 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init(t_app **e, int count)
{
	(void)count;
	*e = malloc(sizeof(**e));
	if (!*e)
		exit_app(*e, 1);
	ft_bzero(*e, sizeof(**e));
	(*e)->print = 1;
}

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

int	exit_app(t_app *e, int code)
{
	if (code != 0)
		ft_putendl_fd("Error", STDERR_FILENO);
	if (e)
	{
		ft_dlstclear(&e->in, free);
		ft_dlstclear(&e->b, free);
		ft_dlstclear(&e->a, free);
		ft_dlstclear(&e->ops, free);
		free(e->sorted);
		free(e);
	}
	exit(code);
}

void	test(t_app *e)
{
	sort_insertion(e);
	ft_putstr_fd("insertion v1 : ", STDOUT_FILENO);
	ft_putnbr_fd(e->size_ops, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	reset(e);
	insertion_sort_v3(e);
	ft_putstr_fd("insertion v3 : ", STDOUT_FILENO);
	ft_putnbr_fd(e->size_ops, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	reset(e);
	sort_greater(e);
	ft_putstr_fd("     greater : ", STDOUT_FILENO);
	ft_putnbr_fd(e->size_ops, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	reset(e);
	sort_radix(e);
	ft_putstr_fd("       radix : ", STDOUT_FILENO);
	ft_putnbr_fd(e->size_ops, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}

int	main(int argc, char *argv[])
{
	t_app	*e;

	init(&e, argc - 1);
	if (!parse_args(e, argv + 1))
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
		test(e);
		//insertion_sort_v3(e);
	else
		sort_radix(e);
	if (PR_STACKS)
		print_stacks(e);
	if (PR_OPS)
		print_operations(e);
	//while(1);
	exit_app(e, 0);
}
