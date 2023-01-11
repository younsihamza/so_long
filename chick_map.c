/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chick_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:49:26 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 17:35:37 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	only_01ecp(char **array)
{
	int		i;
	int		j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (ft_strchr("01ECP", array[i][j]) == NULL)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	chick_len(char **array )
{
	int		i;
	size_t	a;

	i = 1;
	a = ft_strlen(*array, '\0');
	while (array[i])
	{
		if (ft_strlen(array[i], '\0') != a)
			return (1);
		i++;
	}
	return (0);
}

int	simple2(char **array, int *e, int *p, int i)
{
	int	j;
	int	c;

	c = 0;
	j = 0 ;
	while (array[i][j])
	{
		if (array[i][j] == 'E')
			*e += 1;
		else if (array[i][j] == 'P')
			*p += 1;
		else if (array[i][j] == 'C')
			c += 1;
		j++;
	}
	return (c);
}

int	chick_esc(char **array, t_type *r)
{
	int	i ;
	int	e ;
	int	p ;
	int	c ;

	e = 0;
	p = 0;
	c = 0;
	i = 0;
	while (array[i])
	{
		c += simple2(array, &e, &p, i);
		i++;
	}
	r->number_c = c;
	if (e == 1 && p == 1 && c >= 1)
		return (0);
	return (1);
}

int	chick_map(char **array, int *x, int *y, t_type *r)
{
	int	len_colume;
	int	len_row ;

	if (array == NULL)
		return (1);
	len_row = ft_strlen(*array, '\0');
	len_colume = number_of_colum(array);
	*x = len_row;
	*y = len_colume;
	if (only_01ecp(array) != 0 || len_colume <= 1)
		return (1);
	if (chick_len(array) != 0)
		return (1);
	if (chick_esc(array, r) != 0)
		return (1);
	if (check_rectungel(array, len_colume, len_row) != 0)
		return (1);
	if (path_chicks(array, len_row, len_colume, r) != 0)
		return (1);
	return (0);
}
