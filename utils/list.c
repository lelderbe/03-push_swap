/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:27:19 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 16:27:20 by lelderbe         ###   ########.fr       */
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

int	add(t_dlist **lst, int value)
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

int	exist(t_dlist *lst, int value)
{
	while (lst)
	{
		if (*(int *)lst->content == value)
			return (OK);
		lst = lst->next;
	}
	return (FAIL);
}

int	size(t_dlist *lst)
{
	return (ft_dlstsize(lst));
}

int	sorted(t_dlist *lst)
{
	while (lst)
	{
		if (lst->prev && (*(int *)lst->prev->content > *(int *)lst->content))
			return (FAIL);
		lst = lst->next;
	}
	return (OK);
}
