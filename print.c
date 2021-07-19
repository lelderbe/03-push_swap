#include "push_swap.h"

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
	const char	*op[] = {"pa", "pb", "sa", "sb", "ss", "ra", \
							"rb", "rr", "rra", "rrb", "rrr"};
	t_dlist		*lst;

	lst = e->ops;
	while (lst)
	{
		ft_putendl_fd((char *)op[*(int *)lst->content], 1);
		lst = lst->next;
	}
}
