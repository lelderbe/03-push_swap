/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:18:49 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/12 13:37:43 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	i;
	int value;

	i = 0;
	while (i < count)
	{
		if (!(protected_atoi(argv[i], &value) && 
			   !find_value(e->a, value) &&
			   add_value(&e->a, value)))
			return (FAIL);
		i++;
	}
	return (OK);
}
