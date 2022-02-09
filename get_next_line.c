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
	int		len;

	len = 0;
	p_n = NULL;
	if (rest)
	{
		printf("testa\n");
		p_n = ft_strchr(rest, '\n');
		printf("testb\n");
		if (p_n)
		{
			printf("testc\n");
			*p_n = '\0';
			len = ft_strlen_end(rest);
			*line = ft_strdup(rest, len);
			printf("testd\n");
			ft_strcpy(rest, ++p_n);
		}
		else
		{
			len = ft_strlen_end(rest);
			*line = ft_strdup(rest, len);
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
	int			len;
	char		*buf_tmp;

	buf_tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf_tmp):
		return (NULL);
	buf_tmp[BUFFTER_SIZE + 1]= '\0';
	buf[0] = '\0';
	printf("test0\n");
	p_n = check_rest(rest, line);
	printf("test1\n");
	while (!p_n && (byte_was_read))
	{
		printf("test2\n");
		byte_was_read = '\0';
		byte_was_read = read(fd, buf, BUFFER_SIZE);
		printf("test3\n");
		p_n = ft_strchr(buf, '\n');
		printf("test4\n");
		if (p_n)
		{
			printf("test5\n");
			*p_n = '\0';
			p_n++;
			len = ft_strlen_end(buf);
			rest = ft_strdup(p_n, len);
			printf("test6\n");
		}
		printf("test1\n");
		*line = ft_strjoin(*line, buf);
		printf("test7\n");
	}
	return (*line);
}

int main()
{
	int fd;
	char	*line;
	
	fd = 0;
	fd = open("test", O_RDONLY, fd);
	printf("%s\n",get_next_line(fd, &line));
}