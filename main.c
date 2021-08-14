#include"header.h"

int main(int ac, char **av)
{
	game g;

	if (ac != 2 || check_input(av[1]) == 0)
	{
		//print error
		return (1);
	}
	g = init_game(av[1]);;
	if (solve(&g) == 0)
	{
		//print error
		return (1);
	}
	print_game(g);
	return (0);
}
