/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:25:14 by hyujung           #+#    #+#             */
/*   Updated: 2022/02/19 13:05:12 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_c_in_str(char *backup, int nl)
{
	int	i;

	i = 0;
	if (!backup)
		return (0);
	while (backup[i])
	{
		if (backup[i] == (char)nl)
			return ((char *)&(backup[i]));
		i++;
	}
	return (0);
}

char	*readl_m_buf_fr_buf_ret_bc_w_nlnullstr(int fd, char *backup)
{
	char	*buf;
	int		read_byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_byte = 1;
	while (read_byte != 0 && !ft_find_c_in_str(backup, '\n'))
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_byte] = '\0';
		backup = join_m_bcplusbuf_ft_bc_ret_bcplusbuf(backup, buf);
	}
	free(buf);
	return (backup);
}

char	*newbc_m_afternl_strnull_fr_bc_ret_afternl(char *backup)
{
	char	*afternl;
	int		i;
	int		j;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	afternl = (char *)malloc(sizeof(char) * (sln(backup) - i + 1));
	if (!afternl)
		return (NULL);
	j = 0;
	i++;
	while (backup[i])
		afternl[j++] = backup[i++];
	afternl[j] = '\0';
	free(backup);
	return (afternl);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*oneline_nl_or_not;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = readl_m_buf_fr_buf_ret_bc_w_nlnullstr(fd, backup);
	if (!backup)
		return (NULL);
	oneline_nl_or_not = getl_m_beforenl_ret_beforenl_w_strnull(backup);
	backup = newbc_m_afternl_strnull_fr_bc_ret_afternl(backup);
	return (oneline_nl_or_not);
}
