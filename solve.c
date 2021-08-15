/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:30:49 by maabidal          #+#    #+#             */
/*   Updated: 2021/08/15 16:30:52 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int	count_views_on_line(int y, int dir, t_game g)
{
	int	i;
	int	limit;
	int	highest;
	int	count;
	int	s;

	s = g.size;
	i = (dir == 1) * (s - 1);
	limit = (dir == 0) * (s + 1) - 1;
	dir = 1 - (dir == 1) * 2;
	highest = g.grid[i][y];
	count = 1;
	while (i != limit)
	{
		count += highest < g.grid[i][y];
		if (highest < g.grid[i][y])
			highest = g.grid[i][y];
		i += dir;
	}
	return (count);
}

int	can_put_on_line(int x, int y, int val, t_game *g)
{
	int	is_leg;
	int	view_left;
	int	view_right;
	int	s;
	int	i;

	is_leg = 1;
	s = g->size;
	while (++i < s)
		is_leg *= g->grid[(x + i) % s][y] != val;
	g->grid[x][y] = val;
	view_left = count_views_on_line(y, 0, *g);
	view_right = count_views_on_line(y, 1, *g);
	if (x == s - 1)
	{
		is_leg *= view_left == g->view_points[2][y];
		is_leg *= view_right == g->view_points[3][y];
	}
	else
		is_leg *= view_left <= g->view_points[2][y];
	g->grid[x][y] *= is_leg;
	return (is_leg);
}

int	count_views_on_columm(int x, int dir, t_game g)
{
	int	i;
	int	limit;
	int	highest;
	int	count;
	int	s;

	s = g.size;
	i = (dir == 1) * (s - 1);
	limit = (dir == 0) * (s + 1) - 1;
	dir = 1 - (dir == 1) * 2;
	highest = g.grid[x][i];
	count = 1;
	while (i != limit)
	{
		count += highest < g.grid[x][i];
		if (highest < g.grid[x][i])
			highest = g.grid[x][i];
		i += dir;
	}
	return (count);
}

int	can_put_on_columm(int x, int y, int val, t_game *g)
{
	int	s;
	int	is_leg;
	int	view_top;
	int	view_down;
	int	i;

	i = 0;
	is_leg = 1;
	s = g->size;
	g->grid[x][y] = val;
	while (++i < s)
		is_leg *= g->grid[x][(y + i) % s] != val;
	view_top = count_views_on_columm(x, 0, *g);
	view_down = count_views_on_columm(x, 1, *g);
	if (y == s - 1)
	{
		is_leg *= view_top == g->view_points[0][x];
		is_leg *= view_down == g->view_points[1][x];
	}
	else
		is_leg *= view_top <= g->view_points[0][x];
	g->grid[x][y] *= is_leg;
	return (is_leg);
}

int	solve(int x, int y, t_game *g)
{
	int	val;
	int	s;

	size = g->size
	val = 1;
	while (val < s)
	{
		if (can_put_on_line(x, y, val, g) && can_put_on_columm(x, y, val, g))
		{
			if ((x == s - 1 && y == s - 1) || solve((x + 1) % s, y + (x + 1) / s, g))
				return (1);
		}
		val++;
	}
	g->grid[x][y] = 0;
	return (0);
}
