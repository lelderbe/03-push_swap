/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:10:23 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/15 15:18:13 by lelderbe         ###   ########.fr       */
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
}

int	exit_app(t_app *e, int code)
{
	ft_dlstclear(&e->b, free);
	ft_dlstclear(&e->a, free);
	ft_dlstclear(&e->ops, free);
	free(e->sorted);
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

void	print_operations(t_app *e)
{
	char	*op[] = {"pa", "pb", "sa", "sb", "ss", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	t_dlist	*lst;

	lst = e->ops;
	while (lst)
	{
		//printf("%s\n", op[*(int *)lst->content]);
		//printf("*");
		//fflush(stdout);
		ft_putendl_fd(op[*(int *)lst->content], 1);
		lst = lst->next;
	}
}

void	print_sorted(t_app *e)
{
	int	i;

	i = 0;
	while (i < e->count)
	{
		printf("%d ", e->sorted[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_app	*e;

	init(&e, argc - 1);
	if (!parse_args(e, argv + 1))
	{
		ft_putendl_fd("Error", 2);
		exit_app(e, 1);
	}
	if (!e->a || sorted(e->a))
		exit_app(e, 0);
	//print_sorted(e);
	//printf("[0]: %d, [1]: %d\n", get(e->a, 0), get(e->a, 1));
	//print_stacks(e);
	if (size(e->a) == 2)
		sort2(e);
	else if (size(e->a) == 3)
		sort3(e);
	else
		sort_greater(e);
		//sort_a_lot(e);
		//recursion_sort_v2(e);
	print_stacks(e);
	//while(1);
	//printf("[0]: %d, [1]: %d\n", get(e->a, 0), get(e->a, 1));
	print_operations(e);
	exit_app(e, 0);
}
