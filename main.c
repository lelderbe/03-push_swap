/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:10:23 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/14 17:30:59 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init(t_app **e)
{
	*e = malloc(sizeof(**e));
	if (!*e)
		exit(1);
	ft_bzero(*e, sizeof(**e));
	(*e)->print = 1;
}

int	exit_app(t_app *e, int code)
{
	ft_dlstclear(&e->b, free);
	ft_dlstclear(&e->a, free);
	exit(code);
}

static void	print_stack(t_dlist *lst)
{
	while (lst)
	{
		printf("%d ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

void	print_stacks(t_app *e)
{
	printf("a: "), print_stack(e->a), printf("b: "), print_stack(e->b);
}

int	main(int argc, char *argv[])
{
	t_app	*e;

	init(&e);
	if (!parse_args(e, argc - 1, argv + 1))
	{
		ft_putendl_fd("Error", 2);
		exit_app(e, 1);
	}
	if (!e->a || sorted(e->a))
		exit_app(e, 0);
	//printf("[0]: %d, [1]: %d\n", get(e->a, 0), get(e->a, 1));
	//print_stacks(e);
	if (size(e->a) == 2)
		sort2(e);
	else if (size(e->a) == 3)
		sort3(e);
	else
		sort_a_lot(e);
		//recursion_sort_v2(e);
	//print_stacks(e);
	//while(1);
	//printf("[0]: %d, [1]: %d\n", get(e->a, 0), get(e->a, 1));
	exit_app(e, 0);
}
