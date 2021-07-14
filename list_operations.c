/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:53:26 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/14 17:27:51 by lelderbe         ###   ########.fr       */
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

int	get(t_dlist *lst, int index)
{
	int	i;

	i = 0;
	while (lst && i < index)
	{
		lst = lst->next;
		i++;
	}
	return (*(int *)lst->content);
}

int	size(t_dlist *lst)
{
	return (ft_dlstsize(lst));
}

int	get_max_index(t_dlist *lst)
{
	int	value;
	int	index;
	int	i;

	value = *(int *)lst->content;
	index = 0;
	lst = lst->next;
	i = 1;
	while (lst)
	{
		if (*(int *)lst->content > value)
		{
			value = *(int *)lst->content;
			index = i;
		}
		lst = lst->next;
		i++;
	}
	return (index);
}

int	get_min_index(t_dlist *lst)
{
	int	value;
	int	index;
	int	i;

	value = *(int *)lst->content;
	index = 0;
	lst = lst->next;
	i = 1;
	while (lst)
	{
		if (*(int *)lst->content < value)
		{
			value = *(int *)lst->content;
			index = i;
		}
		lst = lst->next;
		i++;
	}
	return (index);
}