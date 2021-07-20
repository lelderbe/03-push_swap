/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:04:29 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 14:04:35 by lelderbe         ###   ########.fr       */
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

int	get_sorted_index(t_app *e, int value)
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

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	make_stack_copy(t_dlist *original, t_dlist **copy)
{
	while (original)
	{
		if (!add(copy, *(int *)original->content))
			return (FAIL);
		original = original->next;
	}
	return (OK);
}
