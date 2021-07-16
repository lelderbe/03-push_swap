/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:47:33 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 12:50:07 by lelderbe         ###   ########.fr       */
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
