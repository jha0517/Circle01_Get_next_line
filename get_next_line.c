/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:12:04 by hyujung           #+#    #+#             */
/*   Updated: 2021/12/11 20:12:47 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*check_rest(char *rest, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (rest)
	{
		p_n = ft_strchr(rest, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(rest);
			ft_strcpy(rest, ++p_n);
		}
		else
		{
			*line = ft_strdup(rest);
			ft_strclr(rest);
		}
	}
	else
	{
		*line = "\0";
	}
	return (p_n);
}

char	*get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			byte_was_read;
	char		*p_n;
	static char	*rest;
	char		*tmp;

	buf[0] = '\0';
	p_n = check_rest(rest, line);
	while (!p_n && (byte_was_read))
	{
		byte_was_read = '\0';
		byte_was_read = read(fd, buf, BUFFER_SIZE);
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			*p_n = '\0';
			p_n++;
			rest = ft_strdup(p_n);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (*line);
}
