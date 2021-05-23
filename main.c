#include "push_swap.h"

static void init(t_app **e)
{
	*e = malloc(sizeof(**e));
	if (!*e)
		exit(1);
	ft_bzero(*e, sizeof(**e));
	(*e)->print = 1;
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
	if (parse_args(e, argc - 1, argv + 1) == 0)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	//print_stacks(e);
	//recursion_sort(e);
	recursion_sort_v2(e);
	//pb(e);
	//pb(e);
	//rrr(e);
	//print_stacks(e);
	return (0);
}
