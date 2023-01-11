/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:49:56 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/11 18:09:55 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct queue
{
	int	*l_x;
	int	*l_y;
	int	front;
	int	rear;
	int	len ;
	int	size;
}t_queue;

void	int_queue(t_queue *p, int x, int y)
{
	p->size = x * y;
	p->l_x = malloc(p->size * sizeof(int));
	p->l_y = malloc(p->size * sizeof(int));
	p->front = 0;
	p->rear = 0;
	p->len = 0;
}

void	enqueue(t_queue *p, int y, int x)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i < p->len)
	{
		if (p->l_x[i] == x && p->l_y[i] == y)
			a++;
		i++;
	}
	if (a == 0)
	{
		p->l_x[p->rear] = x;
		p->l_y[p->rear] = y;
		p->rear++;
		p->len++;
	}
}

int	check_ec(char **array, t_queue *p, t_type *r)
{
	int	i;
	int	e;
	int	c;

	i = 0;
	c = 0;
	e = 0;
	while (i < p->len)
	{
		if (array[p->l_y[i]][p->l_x[i]] == 'E')
			e++;
		if (array[p->l_y[i]][p->l_x[i]] == 'C')
			c++;
		i++;
	}
	if (e == 1 && c == r->number_c)
		return (0);
	return (1);
}

int	simple(char **array, t_queue *p, t_type *r)
{
	while (p->front < p->rear)
	{
		if (array[p->l_y[p->front]][p->l_x[p->front] - 1] != '1')
			enqueue(p, p->l_y[p->front], p->l_x[p->front] - 1);
		if (array[p->l_y[p->front]][p->l_x[p->front] + 1] != '1')
			enqueue(p, p->l_y[p->front], p->l_x[p->front] + 1);
		if (array[p->l_y[p->front] - 1][p->l_x[p->front]] != '1')
			enqueue(p, p->l_y[p->front] - 1, p->l_x[p->front]);
		if (array[p->l_y[p->front] + 1][p->l_x[p->front]] != '1')
			enqueue(p, p->l_y[p->front] + 1, p->l_x[p->front]);
		p->front++;
	}
	return (check_ec(array, p, r));
}

int	path_chicks(char **array, int x, int y, t_type *r)
{
	t_queue	p;
	int		i;
	int		j;
	int		a;

	int_queue(&p, x, y);
	check_position(array, &i, &j);
	enqueue(&p, i, j);
	a = simple(array, &p, r);
	free(p.l_x);
	free(p.l_y);
	return (a);
}
