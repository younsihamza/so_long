/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectungel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:25:43 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 16:12:57 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	number_of_colum(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	simple1(char**array, int len_colume)
{
	int	i;

	i = 0;
	while (array[0][i])
	{
		if (array[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (array[len_colume - 1][i])
	{
		if (array[len_colume - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_rectungel(char**array, int len_colume, int len_row)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	a = simple1(array, len_colume);
	if (a != 0)
		return (1);
	while (i < len_row && array[i])
	{
		if (array[i][0] != '1')
			return (1);
		i++;
	}
	i = 0 ;
	while (i < len_row && array[i])
	{
		if (array[i][len_row - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
