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

char	*ft_strlcpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && len > 0)
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}

int	check_rest(char *rest, char **line)
{
	int	back_slash_pos;
	int	len;
	int	flag;

	flag = 1;
	len = 0;
	back_slash_pos = 0;
	if ((flag != 0) && (rest != NULL))
	{
		len = ft_strlen(rest);
		back_slash_pos = ft_strchr(rest, '\n', len);		
		if (back_slash_pos != -1)
		{
			rest[back_slash_pos] = '\0';
			*line = ft_strdup(rest, back_slash_pos);
			back_slash_pos++;
			ft_strlcpy(rest, &rest[back_slash_pos], BUFFER_SIZE - back_slash_pos);
			flag= 0;
		}
		else
		{
			len = ft_strlen(rest);
			*line = ft_strdup(rest, BUFFER_SIZE);
			ft_strclr(rest);
		}
		
	}
	else
	{
		*line = "\0";
	}
	return (back_slash_pos);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			byte_was_read;
	int			back_slash_pos;
	static char	*rest;
	int			flag;
	char		*line;
	char		*ret;

	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	flag = 1;
	if (fd <= 0 || fd > 1024 || BUFFER_SIZE < 1 || BUFFER_SIZE > 999999)
		return (NULL);
	buf[BUFFER_SIZE]= '\0';
	back_slash_pos = check_rest(rest, &line);
	// printf("test3\n");
	byte_was_read = 1;
	while (flag && (byte_was_read))
	{
		// printf("test4\n");
		byte_was_read = '\0';
		byte_was_read = read(fd, buf, BUFFER_SIZE);
		if (byte_was_read == -1)
			return (NULL);
		// printf("buf : %s\n", buf);
		back_slash_pos = ft_strchr(buf, '\n', BUFFER_SIZE);
		if (back_slash_pos != -1)
		{
			// printf("test4\n");
			buf[back_slash_pos] = '\0';
			back_slash_pos++;
			rest = ft_strdup(&buf[back_slash_pos], BUFFER_SIZE - back_slash_pos);
			flag = 0;
		}
		if(!byte_was_read)
		{
			ft_strclr(buf);
		}
		// printf("test6\n");
		line = ft_strjoin(line, buf);
		// printf("test7\n");
	}
	ret = line;
	// free(line);
	return (line);
}
int	main()
{
	int	fd;

	fd = open("files/empty", O_RDONLY);
	if(fd == -1)
		return (0);
	printf("first line : %s\n", get_next_line(fd));

}