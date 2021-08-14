#include"header.h"
#include<stdio.h>

int main(int ac, char **av)
{
	game g;

	if (ac != 2 || check_input(av[1]) == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	g = init_game(av[1]);;
	if (solve(0, 0, &g) == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	print_game(g);
	return (0);
}
