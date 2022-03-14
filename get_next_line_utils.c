/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:25:14 by hyujung           #+#    #+#             */
/*   Updated: 2022/02/02 19:37:37 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	sln(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*getl_m_beforenl_ret_beforenl_w_strnull(char *backup)
{
	char	*before_nl;
	int		i;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	before_nl = (char *)malloc(sizeof(char) * (i + 2));
	if (!before_nl)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		before_nl[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		before_nl[i] = backup[i];
		i++;
	}
	before_nl[i] = '\0';
	return (before_nl);
}

char	*join_m_bcplusbuf_ft_bc_ret_bcplusbuf(char *backup, char *buf)
{
	char	*bcplusbuf;
	int		i;
	int		j;

	if (!backup)
	{
		backup = (char *)malloc(sizeof(char) * 1);
		backup[0] = '\0';
	}
	if (!backup || !buf)
		return (NULL);
	bcplusbuf = (char *)malloc(sizeof(char) * ((sln(backup) + sln(buf)) + 1));
	if (!bcplusbuf)
		return (NULL);
	i = -1;
	if (backup)
		while (backup[++i])
			bcplusbuf[i] = backup[i];
	j = 0;
	while (buf[j])
		bcplusbuf[i++] = buf[j++];
	bcplusbuf[sln(backup) + sln(buf)] = '\0';
	free(backup);
	return (bcplusbuf);
}
