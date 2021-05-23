#include "push_swap.h"

static void init(t_app *e)
{
	ft_bzero(e, sizeof(*e));
	//printf("size: %lu, e->a : %p, e->b : %p\n", sizeof(*e), e->a, e->b);
	//e->b = 0;
}

static void	print_stack(t_dlist *lst)
{
	//printf("got lst pointer: %p\n", lst);
	while (lst)
	{
		printf("%d ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_app	e;

	//printf("size: %lu, e.a : %p, e.b : %p\n", sizeof(e), e.a, e.b);
	init(&e);
	if (parse_args(&e, argc - 1, argv + 1) == 0)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	printf("a: "), print_stack(e.a), printf("b: "),	print_stack(e.b);
	// do sort
	pb(&e);
	printf("a: "), print_stack(e.a), printf("b: "),	print_stack(e.b);
	sa(&e);
	printf("a: "), print_stack(e.a), printf("b: "),	print_stack(e.b);
	pa(&e);

	printf("a: "), print_stack(e.a), printf("b: "),	print_stack(e.b);
	return (0);
}
