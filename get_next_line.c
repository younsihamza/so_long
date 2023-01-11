/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:03:17 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 16:12:30 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr( char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (*str != (char)c)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

void	help_1(char **s, char **p, int a)
{
	char	*tmp;

	if (!*s && a != 0)
	{
		*s = ft_substr(*p, 0, ft_strlen(*p, '\0') + 1);
		ft_bzero(*p, ft_strlen(*p, '\0'));
	}
	else if (a != 0)
	{
		tmp = *s;
		*s = ft_strjoin(*s, *p);
		free(tmp);
		ft_bzero(*p, ft_strlen(*p, '\0'));
	}
}

char	*help_fn(char **s, char **p)
{
	char	*line;
	char	*tmp;

	if (ft_strlen(*s, '\0') == 0)
	{
		free(*s);
		free(*p);
		return (NULL);
	}
	if (ft_strchr(*s, '\n'))
	{
		line = ft_substr(*s, 0, ft_strlen(*s, '\n'));
		tmp = *s;
		*s = ft_substr(*s, ft_strlen(*s, '\n') + 1, ft_strlen(*s, '\0') + 1);
		free(tmp);
	}
	else
	{
		tmp = *s;
		line = ft_substr(*s, 0, ft_strlen(*s, '\0') + 1);
		free(tmp);
		*s = NULL;
	}
	free(*p);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*p;
	static char		*s;
	char			*line;
	int				a;

	a = 3;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	p = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!p)
		return (NULL);
	while (ft_strchr(s, '\n') == NULL && a)
	{
		a = read(fd, p, BUFFER_SIZE);
		if (a < 0)
		{
			free(p);
			return (NULL);
		}
		help_1(&s, &p, a);
	}
	line = help_fn(&s, &p);
	return (line);
}
