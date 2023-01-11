/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:10:16 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 17:17:49 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len2d(char **c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return (0);
	while (*(c + i))
		i++;
	return (i);
}

char	**join_2d(char **map2d, char *p)
{
	int		len_map;
	int		i;
	char	**array;

	i = 0 ;
	len_map = len2d(map2d);
	array = ft_calloc(sizeof(char *), len_map + 2);
	while (i < len_map)
	{
		array[i] = map2d[i];
		i++;
	}
	array[i] = p;
	return (array);
}

char	**map_transfer(int fd)
{	
	char	**map2d;
	char	**tmp;
	char	*p;

	map2d = NULL;
	p = get_next_line(fd);
	while (p != NULL)
	{
		tmp = map2d;
		map2d = join_2d(tmp, p);
		free(tmp);
		p = get_next_line(fd);
	}
	return (map2d);
}
