/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:16:44 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 16:16:12 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*p;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		*(p + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	i;
	void	*p;

	i = 0;
	p = malloc(size * nitems);
	if (!p)
		return (NULL);
	ft_bzero(p, size * nitems);
	return (p);
}

size_t	ft_strlen(char *p, char a)
{
	size_t	i;

	i = 0;
	if (!p)
		return (0);
	while (*(p + i) != a)
		i++;
	return (i);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	r;
	char	*p;

	j = 0 ;
	i = start ;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s, '\0'))
	{
		p = (char *)ft_calloc(sizeof(char), 1);
		return (p);
	}
	if (ft_strlen(s + start, '\0') > len)
		r = len;
	else
		r = ft_strlen(s + start, '\0');
	p = (char *)ft_calloc(sizeof(char), r + 1);
	if (!p)
		return (NULL);
	while (j < r)
		*(p + j++) = *(s + i++);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1, '\0');
	len_s2 = ft_strlen(s2, '\0');
	j = 0;
	i = 0;
	p = (char *)ft_calloc(sizeof(char), (len_s1 + len_s2) + 1);
	if (!p)
		return (NULL);
	while (*(s1 + j))
		*(p + i++) = *(s1 + j++);
	j = 0;
	while (*(s2 + j))
		*(p + i++) = *(s2 + j++);
	return (p);
}
