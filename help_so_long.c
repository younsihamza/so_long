/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:03:32 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 18:22:21 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	event_help(int keycode, t_type *var, int a)
{
	if (keycode == 13)
		up(var);
	else if (keycode == 0)
		left(var);
	else if (keycode == 2)
		right(var);
	else if (keycode == 1)
		down(var);
	if (a != var->number_move)
	{
		ft_putnbr(var->number_move);
		write(1, "\n", 1);
	}
}

void	image_convert(t_type *var, char **images, char **number)
{
	int	wh[2];

	images[0] = mlx_xpm_file_to_image(var->mlx, "./80-1.xpm", &wh[0], &wh[1]);
	images[1] = mlx_xpm_file_to_image(var->mlx, "./sili-1.xpm", &wh[0], &wh[1]);
	images[2] = mlx_xpm_file_to_image(var->mlx, "./m-1.xpm", &wh[0], &wh[1]);
	images[3] = mlx_xpm_file_to_image(var->mlx, "./h-1.xpm", &wh[0], &wh[1]);
	images[4] = mlx_xpm_file_to_image(var->mlx, "./yo-1.xpm", &wh[0], &wh[1]);
	images[5] = mlx_xpm_file_to_image(var->mlx, "./babo-1.xpm", &wh[0], &wh[1]);
	images[6] = mlx_xpm_file_to_image(var->mlx, "./up.xpm", &wh[0], &wh[1]);
	images[7] = mlx_xpm_file_to_image(var->mlx, "./down-1.xpm", &wh[0], &wh[1]);
	images[8] = mlx_xpm_file_to_image(var->mlx, "./left-1.xpm", &wh[0], &wh[1]);
	number[0] = mlx_xpm_file_to_image(var->mlx, "./0-1.xpm", &wh[0], &wh[1]);
	number[1] = mlx_xpm_file_to_image(var->mlx, "./1-1.xpm", &wh[0], &wh[1]);
	number[2] = mlx_xpm_file_to_image(var->mlx, "./2-1.xpm", &wh[0], &wh[1]);
	number[3] = mlx_xpm_file_to_image(var->mlx, "./3-1.xpm", &wh[0], &wh[1]);
	number[4] = mlx_xpm_file_to_image(var->mlx, "./4-1.xpm", &wh[0], &wh[1]);
	number[5] = mlx_xpm_file_to_image(var->mlx, "./5-1.xpm", &wh[0], &wh[1]);
	number[6] = mlx_xpm_file_to_image(var->mlx, "./6-1.xpm", &wh[0], &wh[1]);
	number[7] = mlx_xpm_file_to_image(var->mlx, "./7-1.xpm", &wh[0], &wh[1]);
	number[8] = mlx_xpm_file_to_image(var->mlx, "./8-1.xpm", &wh[0], &wh[1]);
	number[9] = mlx_xpm_file_to_image(var->mlx, "./9-1.xpm", &wh[0], &wh[1]);
}

int	clos(int keycode, t_type *var)
{
	int	i;
	int	j;
	int	a;

	a = var->number_move;
	j = 0;
	if (keycode == 53)
		exit(mlx_destroy_window(var->mlx, var->win));
	if (var->x == var->e_x && var->e_y == var->y && \
		var->corent_c == var->number_c)
		return (0);
	event_help(keycode, var, a);
	while (j < 50)
	{
		i = 0;
		while (i < 200)
			mlx_pixel_put(var->mlx, var->win, 45 + i++, var->max_y + j, 0);
		j++;
	}
	mlx_string_put(var->mlx, var->win, 50, var->max_y, \
					0xffffff, ft_itoa(var->number_move));
	return (0);
}

void	check_position(char **array, int *i, int *j)
{
	*i = 0;
	while (array[*i])
	{
		*j = 0;
		while (array[*i][*j] && array[*i][*j] != 'P')
		{
			*j += 1;
		}
		if (array[*i][*j] == 'P')
			break ;
		*i += 1;
	}
}
