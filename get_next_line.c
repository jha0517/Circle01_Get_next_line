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

char	*check_rest(char *rest, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (rest)
	{
		p_n = ft_strchr(rest, '\n');
		if (p_n)
		{
			p_n = "\0";
			*line = ft_strdup(rest);
			strcpy(rest, ++p_n);
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
	char		buf[1000 + 1];
	int			byte_was_read;
	char		*p_n;
	int			flag;
	static char	*rest;

	flag = 1;
	check_rest(rest, line);
	while (flag && byte_was_read)
	{
		byte_was_read = '\0';
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			printf("buf : %s", buf);
			*p_n = '\0';
			flag = 0;
			p_n++;
			printf("before p_n : %s\n", p_n);
			rest = ft_strdup(p_n);
			printf("after p_n : %s\n", p_n);
		}
		*line = ft_strjoin(*line, buf);
		printf("*line : %s\n", *line);
		byte_was_read = read(fd, buf, 1000);
	}
	return (*line);
}

int main()
{
	int		fd;
	char	*line;

	fd = open("test.c", O_RDONLY);
	printf("%s\n", get_next_line(fd, &line));
}