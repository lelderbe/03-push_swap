#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

# define APP_NAME	"push_swap"

//# define PRINT

typedef struct s_app {
	t_dlist		*a;
	t_dlist		*b;
	int			print;
}				t_app;

int		parse_args(t_app *e, int count, char **argv);
void	print_stacks(t_app *e);

void	recursion_sort(t_app *e);
void	recursion_sort_v2(t_app *e);

void	pa(t_app *e);
void	pb(t_app *e);

void	sa(t_app *e);
void	sb(t_app *e);
void	ss(t_app *e);

void	ra(t_app *e);
void	rb(t_app *e);
void	rr(t_app *e);

void	rra(t_app *e);
void	rrb(t_app *e);
void	rrr(t_app *e);

#endif
