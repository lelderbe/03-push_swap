/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:12:44 by lelderbe          #+#    #+#             */
/*   Updated: 2021/07/20 18:30:04 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_result(int count, char **remainder, char **line, char *found)
{
	if (!found)
	{
		if (count == -1)
		{
			free(*remainder);
			*remainder = 0;
			return (-1);
		}
		if (count == 0)
		{
			*line = *remainder;
			*remainder = 0;
			return (0);
		}
	}
	found[0] = '\0';
	*line = *remainder;
	*remainder = ft_strjoin(found + 1, 0);
	if (!*remainder)
		return (-1);
	return (1);
}

static void	update(char **buf, char **remainder, int *count)
{
	char		*ptr;

	if (*count != -1)
	{
		(*buf)[*count] = '\0';
		ptr = *remainder;
		*remainder = ft_strjoin(*remainder, *buf);
		free(ptr);
		if (!*remainder)
			*count = -1;
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	char		*found;
	int			count;

	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!line || BUFFER_SIZE <= 0 || !buf)
		return (-1);
	found = ft_strchr(remainder, '\n');
	while (!found)
	{
		count = read(fd, buf, BUFFER_SIZE);
		update(&buf, &remainder, &count);
		if (count == 0 || count == -1)
			break ;
		found = ft_strchr(remainder, '\n');
	}
	free(buf);
	return (get_result(count, &remainder, line, found));
}
