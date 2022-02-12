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

void	ft_strclr(char *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
	{
		*(s + i) = '\0';
		i++;
	}
}

int	ft_strchr(const char *str, int i, int len)
{
	char	*ptr;
	int	cpt;

	cpt = len;
	ptr = (char *) str;
	while (*ptr != (char)i && cpt >= 0 && ptr)
	{
		if (cpt == 0)
			return (-1);
		if (ptr)
			ptr++;
		else
			return (len-cpt);
		cpt--;
	}
	return (len - cpt);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*result;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	str = result;
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (str);
}

char	*ft_strdup(const char *src, int len)
{
	char	*dest;
	int		i;

	i = 0;
	if(!src)
		return (NULL);
	dest = malloc(sizeof(char) * len + 1);
	if (!(dest))
		return (NULL);
	while (src[i] && len > 0)
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}