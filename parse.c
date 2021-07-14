/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:18:49 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/14 17:31:21 by lelderbe         ###   ########.fr       */
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

int	parse_args(t_app *e, int count, char **argv)
{
	int		i;
	int		value;
	char	*str;

	i = 0;
	while (i < count)
	{
		str = ft_strtrim(argv[i], " ");
		if (!(str
				&& has_digit(str)
				&& protected_atoi(str, &value)
				&& !exist(e->a, value)
				&& add(&e->a, value)))
		{
			free(str);
			return (FAIL);
		}
		free(str);
		i++;
	}
	return (OK);
}
