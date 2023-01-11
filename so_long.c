/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:51:40 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 18:46:12 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(void)
{
	write(1, "good dog", 8);
	exit(0);
}

void	drow_map(char **map2d, t_type *var)
{
	int	i;
	int	j;

	var->e_x = 0;
	var->e_y = 0;
	i = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			help_dow_map(map2d, var, i, j);
			j++;
		}
		i++;
	}
}

void	so_long(char **map2d)
{
	char	*images[9];
	char	*number[10];
	int		x;
	int		y;
	t_type	var;

	var.number = number;
	var.corent_c = 0;
	if (chick_map(map2d, &x, &y, &var) != 0)
		exit(write(2, "map is not valide", 18));
	var.size = x * y;
	var.map2d = map2d;
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, x * 50, (y + 1) * 50, "DOG EAT HOTDOG");
	var.max_x = x * 50;
	var.max_y = y * 50;
	image_convert(&var, images, number);
	var.images = images;
	drow_map(map2d, &var);
	var.number_move = 0;
	mlx_key_hook(var.win, clos, &var);
	mlx_hook(var.win, 17, 1L << 17, close_win, &var);
	mlx_loop(var.mlx);
}

void	check_ber(char **argc)
{
	char	*a;
	int		i;
	int		j;

	j = 0;
	i = 0 ;
	a = " .ber";
	while (argc[1][i])
		i++;
	i -= 1;
	j = 4;
	while (argc[1][i] == a[j])
	{
		j--;
		i--;
	}
	if (j != 0)
		exit(0);
}

int	main(int argv, char *argc[])
{
	int		fd;
	char	**map2d;

	if (argv != 2)
		return (0);
	fd = open(argc[1], O_RDONLY);
	if (fd == -1)
		return (0);
	check_ber(argc);
	map2d = map_transfer(fd);
	so_long(map2d);
}
