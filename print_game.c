#include "header.h"

void	print_game(game g)
{
	int	i;

	i = -1;
	while (++i < GAME_SIZE)
	{
		ft_putstr(g.grid[i]);
		if (i != GAME_SIZE - 1)
			ft_putchar("\n");
	}
}
