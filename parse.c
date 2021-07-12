/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:18:49 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/12 14:50:51 by lelderbe         ###   ########.fr       */
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

static int	*make_content(int value)
{
	int	*result;
    
	result = malloc(sizeof(*result));
	if (!result)
		return (FAIL);
	*result = value;
	return (result);
}

static int	add_value(t_dlist **lst, int value)
{
	int		*content;
	t_dlist	*elem;

	content = make_content(value);
	if (!content)
		return (FAIL);
	elem = ft_dlstnew(content);
	if (!elem)
		return (FAIL);
	ft_dlstadd_back(lst, elem);
	return (OK);
}

static int	find_value(t_dlist *lst, int value)
{
	while (lst)
	{
		if (*(int *)lst->content == value)
			return (OK);
		lst = lst->next;
	}
	return (FAIL);
}

int	parse_args(t_app *e, int count, char **argv)
{
	int		i;
	int 	value;
	char	*str;

	i = 0;
	while (i < count)
	{
		str = ft_strtrim(argv[i], " ");
		if (!(str &&
			has_digit(str) &&
			protected_atoi(str, &value) && 
			!find_value(e->a, value) &&
			add_value(&e->a, value)))
		{
			free(str);
			return (FAIL);
		}
		free(str);
		i++;
	}
	return (OK);
}
