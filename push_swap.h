#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

# define APP_NAME	"push_swap"

typedef struct s_app {
	t_dlist		*a;
	t_dlist		*b;
}				t_app;

int		parse_args(t_app *e, int count, char **argv);

void	pa(t_app *e);
void	pb(t_app *e);
void	sa(t_app *e);
void	sb(t_app *e);

#endif
