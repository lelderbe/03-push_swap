/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:10:23 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 14:05:09 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init(t_app **e, int count)
{
	*e = malloc(sizeof(**e));
	if (!*e)
		exit(1);
	ft_bzero(*e, sizeof(**e));
	(*e)->print = 1;
	(*e)->count = count;
	(*e)->size_a = count;
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
	ft_dlstclear(&e->in, free);
	ft_dlstclear(&e->b, free);
	ft_dlstclear(&e->a, free);
	ft_dlstclear(&e->ops, free);
	free(e->sorted);
	free(e);
	exit(code);
}

void	test(t_app *e, char *title)
{
	ft_putendl_fd(title, STDOUT_FILENO);
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
	if (!parse_args(e, argv + 1) || !make_stack_copy(e->in, &e->a))
		exit_app(e, 1);
	if (!e->a || sorted(e->a))
		exit_app(e, 0);
	if (size(e->a) == 2)
		sort2(e);
	else if (size(e->a) == 3)
		sort3(e);
	else if (size(e->a) < 2500)
		//test(e, "<2500");
		insertion_sort_v3(e);
	else
		sort_radix(e);
	//while(1);
	if (PRINT_OPS)
		print_operations(e);
	exit_app(e, 0);
}
