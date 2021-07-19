/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:10:23 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 14:30:00 by lelderbe         ###   ########.fr       */
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

int	exit_app(t_app *e, int code)
{
	if (code != 0)
		ft_putendl_fd("Error", 2);
	ft_dlstclear(&e->in, free);
	ft_dlstclear(&e->b, free);
	ft_dlstclear(&e->a, free);
	ft_dlstclear(&e->ops, free);
	free(e->sorted);
	//free(e); //?
	exit(code);
}

static void	test(t_app *e, char *desc)
{
	sort_insertion(e);
	printf("%s v1 count: %d\n", desc, size(e->ops));
	reset(e);
	insertion_sort_v3(e);
	printf("%s v3 count: %d\n", desc, size(e->ops));
	reset(e);
	sort_greater(e);
	printf("%s gt count: %d\n", desc, size(e->ops));
	reset(e);
	sort_radix(e);
	printf("%s rx count: %d\n", desc, size(e->ops));
}

int	main(int argc, char *argv[])
{
	t_app	*e;

	init(&e, argc - 1);
	if (!parse_args(e, argv + 1) || !make_copy(e->in, &e->a))
		exit_app(e, 1);
	if (!e->a || sorted(e->a))
		exit_app(e, 0);
	//print_stacks(e);
	if (size(e->a) == 2)
		sort2(e);
	else if (size(e->a) == 3)
		sort3(e);
	else if (size(e->a) < 10)
		test(e, "<10");
		//sort_insertion(e);
	else if (size(e->a) < 40)
		test(e, "<40");
	else if (size(e->a) < 100)
		test(e, "<100");
	else if (size(e->a) < 500)
		test(e, "<500");
	else if (size(e->a) < 1000)
		test(e, "<1000");
	else
		test(e, ">1000");
	//print_stacks(e);
	//while(1);
	printf("smalls count: %d\n", size(e->ops));
	//print_operations(e);
	exit_app(e, 0);
}
