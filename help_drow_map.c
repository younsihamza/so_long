/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_drow_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:36:54 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 18:45:50 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	simple_drow(t_type *var, int i, int j)
{
	int	x;
	int	y;

	x = j * 50;
	y = i * 50;
	mlx_put_image_to_window(var->mlx, var->win, \
				var->images[3], x, y);
		var->e_x = x;
		var->e_y = y;
}

void	help_dow_map(char **map2d, t_type *var, int i, int j)
{
	int	x;
	int	y;

	x = j * 50;
	y = i * 50;
	if (map2d[i][j] == '1')
		mlx_put_image_to_window(var->mlx, \
				var->win, var->images[0], x, y);
	else if (map2d[i][j] == '0')
		mlx_put_image_to_window(var->mlx, var->win, \
				var->images[1], x, y);
	else if (map2d[i][j] == 'C')
		mlx_put_image_to_window(var->mlx, var->win, \
				var->images[2], x, y);
	else if (map2d[i][j] == 'E')
		simple_drow(var, i, j);
	else if (map2d[i][j] == 'P')
	{
		mlx_put_image_to_window(var->mlx, var->win, \
				var->images[4], x, y);
		var->x = x;
		var->y = y;
	}
}
