/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:46:44 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 17:25:51 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*ptr;
	size_t	size;

	if (!s1 && !s2)
		return (0);
	size = 0;
	if (s1)
		size = size + ft_strlen(s1);
	if (s2)
		size = size + ft_strlen(s2);
	result = malloc(sizeof(*result) * (size + 1));
	if (!result)
		return (0);
	ptr = result;
	while (s1 && *s1)
		*ptr++ = *s1++;
	while (s2 && *s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (result);
}
