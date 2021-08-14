#include "header.h"
#include<stdio.h>

game init_game(char* av)
{
	game g;
	int x;
	int	y;
	int index;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			g.grid[x][y] = 0;
			index = x * 8 + y * 2;
			g.view_points[x][y] = av[index] - '0';
		}
	}
	return (g);
}
