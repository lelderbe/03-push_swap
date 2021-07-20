/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:44:43 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 19:51:27 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init(t_app **e, int count)
{
	(void)count;
	*e = malloc(sizeof(**e));
	if (!*e)
		return (FAIL);
	ft_bzero(*e, sizeof(**e));
	(*e)->print = 1;
	return (OK);
}

static int	eq(const char *s1, const char *s2)
{
	int	len;

	if (!s1 && !s2)
		return (OK);
	if (!s1 || !s2)
		return (FAIL);
	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	if (ft_strncmp(s1, s2, len) == 0)
		return (OK);
	return (FAIL);
}

static int	do_op(t_app *e, char *s)
{
	int			i;
	int			op;
	const char	*ops[] = {"pa", "pb", "sa", "sb", "ss", "ra", \
							"rb", "rr", "rra", "rrb", "rrr"};
	const t_op	cmds[] = {pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr};

	i = 0;
	op = -1;
	while (i < 11)
	{
		if (eq(s, ops[i]))
		{
			op = i;
			break ;
		}
		i++;
	}
	if (op == -1)
		return (FAIL);
	cmds[i](e);
	return (OK);
}

static void	print_result(t_app *e)
{
	if (sorted(e->a) && size(e->b) == 0)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

int	main(int argc, char *argv[])
{
	t_app	*e;
	int		result;
	char	*line;

	if (!init(&e, argc) || !parse_args(e, argv + 1))
		exit_app(e, 1);
	if (!e->a)
		exit_app(e, 0);
	result = -1;
	while (result != 0)
	{
		result = get_next_line(STDIN_FILENO, &line);
		if (result == 1 && !do_op(e, line))
		{
			free(line);
			exit_app(e, 1);
		}
		if (result == -1)
			exit_app(e, 1);
		free(line);
	}
	print_result(e);
	exit_app(e, 0);
}
