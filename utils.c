/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:22:21 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/16 12:57:23 by lelderbe         ###   ########.fr       */
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
