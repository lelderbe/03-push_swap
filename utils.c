/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:22:21 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/14 17:30:32 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (OK);
	return (FAIL);
}

int	protected_atoi(const char *str, int *value)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((sign > 0 && result > INT_MAX)
			|| (sign < 0 && result > (INT_MAX + (long)1)))
			return (FAIL);
		str++;
	}
	if (*str != '\0')
		return (FAIL);
	*value = result * sign;
	return (OK);
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

int	get_arr_index(t_app *e, int value)
{
	int	i;

	i = 0;
	while (i < e->count)
	{
		if (e->sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/*
int	get(t_dlist *lst, int index)
{
	int i;

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

int	max_index(t_dlist *lst)
{
	int value;
	int index;
	int i;

	value = *(int *)lst->content;
	index = 0;
	//value = get(lst, 0);
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

int	min_index(t_dlist *lst)
{
	int value;
	int index;
	int i;

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
*/
/*
int	min2_index(t_dlist *lst)
{
	int min1;
	int min2;
	int index;
	int i;

	if (*(int *)lst->content < *(int *)lst->next->content)
	{
		min1 = *(int *)lst->content;
		min2 = *(int *)lst->next->content;
	}
	value = *(int *)lst->content;
	index = 0;
	lst = lst->next->next;
	i = 2;
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
*/
/*
int	check_atoi(char *s, int min, int max)
{
	int	value;
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (FAIL);
		i++;
	}
	value = cub_atoi(s);
	if (value >= min && value <= max)
		return (OK);
	return (FAIL);
}
*/
