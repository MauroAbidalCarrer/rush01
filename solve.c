/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:16:55 by kychoi            #+#    #+#             */
/*   Updated: 2021/08/15 12:43:56 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_views_on_line(int y, int dir, t_game g)
{
	int	i;
	int	limit;
	int	highest;
	int	count;

	i = (dir == 1) * 3;
	limit = (dir == 0) * 5 - 1;
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

	is_leg = 1;
	is_leg *= g->grid[(x + 1) % 4][y] != val;
	is_leg *= g->grid[(x + 2) % 4][y] != val;
	is_leg *= g->grid[(x + 3) % 4][y] != val;
	g->grid[x][y] = val;
	view_left = count_views_on_line(y, 0, *g);
	view_right = count_views_on_line(y, 1, *g);
	if (x == 3)
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

	i = (dir == 1) * 3;
	limit = (dir == 0) * 5 - 1;
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
	int	is_leg;
	int	view_top;
	int	view_down;

	is_leg = 1;
	is_leg *= g->grid[x][(y + 1) % 4] != val;
	is_leg *= g->grid[x][(y + 2) % 4] != val;
	is_leg *= g->grid[x][(y + 3) % 4] != val;
	g->grid[x][y] = val;
	view_top = count_views_on_columm(x, 0, *g);
	view_down = count_views_on_columm(x, 1, *g);
	if (y == 3)
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

	val = 1;
	while (val < 5)
	{
		if (can_put_on_line(x, y, val, g) && can_put_on_columm(x, y, val, g))
		{
			if ((x == 3 && y == 3) || solve((x + 1) % 4, y + (x + 1) / 4, g))
				return (1);
		}
		val++;
	}
	g->grid[x][y] = 0;
	return (0);
}
