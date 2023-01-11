/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:22:38 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 17:06:48 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cole(t_type *var)
{
	if (var->map2d[var->y / 50][var->x / 50] == 'C')
	{
		var->map2d[var->y / 50][var->x / 50] = '0';
		var->corent_c++;
		put_number_base(var->corent_c, var, var->max_x / 2);
	}
	var->number_move++;
}

void	up(t_type *var)
{	
	if (var->map2d[(var->y - 50) / 50][var->x / 50] == 'E' &&
		var->corent_c == var->number_c)
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[1], var->x, var->y);
		var->y = var->y - 50;
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[3], var->x, var->y);
	}
	else if (var->map2d[(var->y - 50) / 50][var->x / 50] != '1' )
	{
		if (var->map2d[var->y / 50][var->x / 50] == 'E')
		{
			mlx_put_image_to_window(var->mlx, var->win,
				var->images[3], var->x, var->y);
		}
		else
			mlx_put_image_to_window(var->mlx, var->win, \
				var->images[1], var->x, var->y);
		var->y = var->y - 50;
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[6], var->x, var->y);
		cole(var);
	}
}

void	left(t_type *var)
{
	if ((var->map2d[var-> y / 50][(var->x - 50) / 50]) == 'E' &&
		var->corent_c == var->number_c)
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[1], var->x, var->y);
		var->x = var->x - 50;
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[3], var->x, var->y);
	}
	else if ((var->map2d[var-> y / 50][(var->x - 50) / 50]) != '1')
	{
		if (var->map2d[var->y / 50][var->x / 50] == 'E')
		{
			mlx_put_image_to_window(var->mlx, var->win,
				var->images[3], var->x, var->y);
		}
		else
			mlx_put_image_to_window(var->mlx, var->win, \
				var->images[1], var->x, var->y);
		var->x = var->x - 50;
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[8], var->x, var->y);
		cole(var);
	}
}

void	down(t_type *var)
{
	if (var->map2d[(var->y + 50) / 50][var->x / 50] == 'E' &&
		var->corent_c == var->number_c)
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[1], var->x, var->y);
		var->y = var->y + 50;
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[3], var->x, var->y);
	}
	else if (var->map2d[(var->y + 50) / 50][var->x / 50] != '1' )
	{
		if (var->map2d[var->y / 50][var->x / 50] == 'E')
		{
			mlx_put_image_to_window(var->mlx, var->win,
				var->images[3], var->x, var->y);
		}
		else
			mlx_put_image_to_window(var->mlx, var->win, \
				var->images[1], var->x, var->y);
		var->y = var->y + 50;
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[7], var->x, var->y);
		cole(var);
	}
}

void	right(t_type *var)
{
	if ((var->map2d[var->y / 50][(var->x + 50) / 50]) == 'E' &&
		var->corent_c == var->number_c)
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[1], var->x, var->y);
		var->x = var->x + 50;
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[3], var->x, var->y);
	}
	else if ((var->map2d[var->y / 50][(var->x + 50) / 50]) != '1' )
	{
		if (var->map2d[var->y / 50][var->x / 50] == 'E')
		{
			mlx_put_image_to_window(var->mlx, var->win,
				var->images[3], var->x, var->y);
		}
		else
			mlx_put_image_to_window(var->mlx, var->win, \
				var->images[1], var->x, var->y);
		var->x = var->x + 50;
		mlx_put_image_to_window(var->mlx, var->win,
			var->images[5], var->x, var->y);
		cole(var);
	}
}
