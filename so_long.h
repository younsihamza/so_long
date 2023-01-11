/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:59:45 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 18:46:36 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# define BUFFER_SIZE 1

typedef struct s_type
{
	void	*mlx;
	void	*win;
	char	**map2d;
	char	**images;
	char	**number;
	int		e_x;
	int		e_y;
	int		x;
	int		y;
	int		number_move;
	int		number_c;
	int		corent_c;
	int		size;
	int		max_x;
	int		max_y;
}t_type;
void	*ft_calloc(size_t nitems, size_t size);
void	up(t_type *var);
char	*ft_itoa(int n);
void	left(t_type *var);
void	down(t_type *var);
void	right(t_type *var);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char *p, char a);
char	*ft_substr(char *s, size_t start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
char	*get_next_line(int fd);
char	*recu(int fd);
int		chick_map(char **array, int *x, int *y, t_type *r);
void	ft_putnbr(int number);
char	**map_transfer(int fd);
char	*ft_strchr( char *str, int c);
int		path_chicks(char **array, int x, int y, t_type *r);
int		check_rectungel(char**array, int len_colume, int len_row);
int		number_of_colum(char **array);
int		number_of_c(char **array);
void	put_number_base(unsigned int number, t_type *var, int x);
int		clos(int keycode, t_type *var);
void	image_convert(t_type *var, char **images, char **number);
void	check_position(char **array, int *i, int *j);
void	help_dow_map(char **map2d, t_type *var, int i, int j);

#endif