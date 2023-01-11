/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:12:45 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 17:06:58 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_number_base(unsigned int number, t_type *var, int x)
{
	if (number < 10)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->number[number], \
		x, var->max_y);
		return ;
	}
	put_number_base(number / 10, var, x - 50);
	mlx_put_image_to_window(var->mlx, var->win, \
		var->number[number % 10], x, var->max_y);
}
