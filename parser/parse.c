/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:18:49 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 20:13:34 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	make_sorted(t_app *e)
{
	int		i;

	e->sorted = malloc(sizeof(*e->sorted) * e->count);
	if (!e->sorted)
		return (FAIL);
	i = 0;
	while (i < e->count)
	{
		e->sorted[i] = get(e->in, i);
		i++;
	}
	array_bubble_sort(e->sorted, e->count);
	return (OK);
}

static int	add_value(t_app *e, char *str)
{
	int		value;

	if (!(str
			&& has_digit(str)
			&& protected_atoi(str, &value)
			&& !exist(e->in, value)
			&& add(&e->in, value)))
	{
		return (FAIL);
	}
	return (OK);
}

static int	parse_split(t_app *e, char **argv)
{
	int		i;
	char	**parts;

	i = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			parts = ft_split(argv[i], ' ');
			if (!parts)
				return (FAIL);
			if (!parse_split(e, parts))
			{
				free_split(parts);
				return (FAIL);
			}
			free_split(parts);
		}
		else if (!add_value(e, argv[i]))
			return (FAIL);
		i++;
	}
	return (OK);
}

static void	recode_data(t_app *e)
{
	t_dlist	*lst;

	lst = e->in;
	while (lst)
	{
		*(int *)lst->content = get_sorted_index(e, *(int *)lst->content);
		lst = lst->next;
	}
}

int	parse_args(t_app *e, char **argv)
{
	if (!parse_split(e, argv))
		return (FAIL);
	e->count = size(e->in);
	if (!make_sorted(e))
		return (FAIL);
	recode_data(e);
	if (!make_stack_copy(e->in, &e->a))
		return (FAIL);
	e->size_a = e->count;
	return (OK);
}
