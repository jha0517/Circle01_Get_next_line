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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int     check_rest(char *rest, char **line);
// char    *get_next_line(int fd, char **line);
char    *get_next_line(int fd);
void	ft_strclr(char *s);
int     ft_strchr(const char *str, int i, int len);
int     ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src, int len);

#endif