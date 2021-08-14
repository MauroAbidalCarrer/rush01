#include "header.h"

void print_game(game g)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			ft_putchar('0' + g.grid[x][y]);
			if (x != 3)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void print_game_with_view_points(game g)
{
	int	x;
	int	y;

	y = -1;
	ft_putchar(' ');
	ft_putchar(' ');
	while (++y < 4)
	{
		ft_putchar('0' + g.view_points[0][y]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	y = -1;
	while (++y < 4)
	{
		ft_putchar('0' + g.view_points[2][y]);
		ft_putchar(' ');
		x = -1;
		while (++x < 4)
		{
			ft_putchar('0' + g.grid[x][y]);
			ft_putchar(' ');
		}
		ft_putchar('0' + g.view_points[3][y]);
		ft_putchar('\n');
	}
	ft_putchar(' ');
	ft_putchar(' ');
	y = -1;
	while (++y < 4)
	{
		ft_putchar('0' + g.view_points[1][y]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	ft_putchar('\n');
}
