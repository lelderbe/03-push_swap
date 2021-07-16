/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:53:26 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 12:50:27 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_index(t_dlist *lst, int value)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (*(int *)lst->content == value)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

int	get_insert_pos(t_dlist *lst, int value)
{
	int	i;
	int	pos;
	int	curr;
	int	diff;

	pos = -1;
	diff = -1;
	i = 0;
	while (lst)
	{
		curr = *(int *)lst->content;
		if (curr > value)
		{
			if (diff == -1 || diff > curr - value)
			{
				diff = curr - value;
				pos = i;
			}
		}
		if (pos == -1 && lst->prev && *(int *)lst->prev->content > curr)
			pos = i;
		lst = lst->next;
		i++;
	}
	return (pos);
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
