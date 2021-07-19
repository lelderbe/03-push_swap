/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:18:49 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 12:45:48 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_digit(const char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s))
			return (OK);
		s++;
	}
	return (FAIL);
}

static void	array_bubble_sort(int *arr, int count)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

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
	int		i;
	int		value;
	char	*str;

	i = 0;
	while (i < e->count)
	{
		str = ft_strtrim(argv[i], " ");
		if (!(str
				&& has_digit(str)
				&& protected_atoi(str, &value)
				&& !exist(e->in, value)
				&& add(&e->in, value)))
		{
			free(str);
			return (FAIL);
		}
		free(str);
		i++;
	}
	if (!make_sorted(e))
		return (FAIL);
	recode_data(e);
	return (OK);
}
