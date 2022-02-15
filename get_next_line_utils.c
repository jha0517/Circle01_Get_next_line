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
		// printf("s + i = %c\n", *(s+i));
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
	// printf("len s1 -%i, len s2 -%i\n",ft_strlen(s1), ft_strlen(s2));
	// printf("total len : %i\n", len);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	str = result;
	while (*s1)
	{
		*result = *s1;
		s1++;
		result++;
	}
	while (*s2)
	{
		// printf("*s2: %c\n", *s2);
		*result = *s2;
		result++;
		s2++;
	}
	// printf("last carac : %c\n", *(result - 1));
	*result = '\0';
	// free(result);
	// printf("return str : %s\n", str);
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