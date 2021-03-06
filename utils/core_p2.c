/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:22:55 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 17:37:11 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_app(t_app *e, int code)
{
	if (code != 0)
		ft_putendl_fd("Error", STDERR_FILENO);
	if (e)
	{
		ft_dlstclear(&e->in, free);
		ft_dlstclear(&e->b, free);
		ft_dlstclear(&e->a, free);
		ft_dlstclear(&e->ops, free);
		free(e->sorted);
		free(e);
	}
	exit(code);
}

int	has_digit(const char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s))
			return (OK);
		s++;
	}
	return (FAIL);
}

void	free_split(char **s)
{
	long	i;

	i = 0;
	while (s && s[i])
		free(s[i++]);
	free(s);
}

void	array_bubble_sort(int *arr, int count)
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

void	recode_data(t_app *e)
{
	t_dlist	*lst;

	lst = e->in;
	while (lst)
	{
		*(int *)lst->content = get_sorted_index(e, *(int *)lst->content);
		lst = lst->next;
	}
}
