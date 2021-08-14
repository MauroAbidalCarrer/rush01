#include"header.h"
#include<stdio.h>


int count_views_on_line(int x, int y, int dir, game g)
{
	int	i;
	int limit;
	int	highest;
	int	count;

	i = (dir == 1) * 3;
	limit = (dir == 0) * 5 - 1;
	dir = 1 - (dir == 1) * 2;
	//printf("count called, i: %d, limit: %d, dir: %d\n", i, limit, dir);
	highest = g.grid[i][y];
	//printf("highest: %d\n", highest);
	count = 1;
	while (i != limit)
	{
		count += highest < g.grid[i][y];
		if (highest < g.grid[i][y])
			highest = g.grid[i][y];
		i += dir;
	}
	//printf("count: %d\n\n", count);
	return (count);
}

int can_put_on_line(int x, int y, int val, game *g)
{
	int is_leg;
	int view_left;
	int view_right;

	is_leg = 1;
//	printf("called, (%d, %d), val: %d\n", x, y, val);
	//check for duplicates
	is_leg *= g->grid[(x + 1) % 4][y] != val;
	is_leg *= g->grid[(x + 2) % 4][y] != val;
	is_leg *= g->grid[(x + 3) % 4][y] != val;
//	printf("%s duplicates\n", is_leg ? "no" : "found");

	//check for view points
	//printf("putting val at (%d, %d)\n", x, y);
	g->grid[x][y] = val;
	view_left = count_views_on_line(x, y, 0, *g);
	view_right = count_views_on_line(x, y, 1, *g);
	//printf("right count: %d, left count: %d\n", view_left, view_right);
	if (x == 3)
	{
		is_leg *= view_left == g->view_points[2][y];
		is_leg *= view_right == g->view_points[3][y];
//		printf("view right: %d, view left %d\n",view_right, view_left);
//		printf("view_point right: %d, view_point left %d\n",g->view_points[3][y], g->view_points[2][y]);
//		printf("check_right: %d, check_left %d\n",view_right == g->view_points[3][y], view_left == g->view_points[2][y]);
	}
	else
		is_leg *= view_left <= g->view_points[2][y];
	//printf("move is%s legal\n", is_leg ? "" : " NOT");
	g->grid[x][y] *= is_leg;
	return (is_leg);
}

int count_views_on_columm(int x, int y, int dir, game g)
{
	int	i;
	int limit;
	int	highest;
	int	count;

	i = (dir == 1) * 3;
	limit = (dir == 0) * 5 - 1;
	dir = 1 - (dir == 1) * 2;
	//printf("count called, i: %d, limit: %d, dir: %d\n", i, limit, dir);
	highest = g.grid[x][i];
	//printf("highest: %d\n", highest);
	count = 1;
	while (i != limit)
	{
		count += highest < g.grid[x][i];
		if (highest < g.grid[x][i])
			highest = g.grid[x][i];
		i += dir;
	}
	//printf("count: %d\n\n", count);
	return (count);
}

int can_put_on_columm(int x, int y, int val, game *g)
{
	int is_leg;
	int view_top;
	int view_down;

	is_leg = 1;
//	printf("called, (%d, %d), val: %d\n", x, y, val);
	//check for duplicates
	is_leg *= g->grid[x][(y + 1) % 4] != val;
	is_leg *= g->grid[x][(y + 2) % 4] != val;
	is_leg *= g->grid[x][(y + 3) % 4] != val;
//	printf("%s duplicates\n", is_leg ? "no" : "found");

	//check for view points
	//printf("putting val at (%d, %d)\n", x, y);
	g->grid[x][y] = val;
	view_top = count_views_on_columm(x, y, 0, *g);
	view_down = count_views_on_columm(x, y, 1, *g);
	//printf("right count: %d, left count: %d\n", view_left, view_right);
	if (y == 3)
	{
		is_leg *= view_top == g->view_points[0][x];
		is_leg *= view_down == g->view_points[1][x];
	}
	else
		is_leg *= view_top <= g->view_points[0][x];
	//printf("move is%s legal\n", is_leg ? "" : " NOT");
	g->grid[x][y] *= is_leg;
	return (is_leg);
}

int	solve(int x, int y, game *g)
{
	int	val;

	val = 1;
	while (val < 5)
	{
//		printf("(%d, %d) val: %d, line: %d, columm: %d\n", x, y, val, can_put_on_line(x, y, val, g), can_put_on_columm(x, y, val, g));
		if (can_put_on_line(x, y, val, g) && can_put_on_columm(x, y, val, g))
		{
//			print_game_with_view_points(*g);
//			printf("next x: %d\n", (x + 1) % 4);
			if ((x == 3 && y == 3) || solve((x + 1) % 4, y + (x + 1) / 4, g))
				return (1);
		}
		val++;
	}
	g->grid[x][y] = 0;
	return (0);
}
