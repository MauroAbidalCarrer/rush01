#include <stdlib.h>
#include <stdio.h>
#include"header.h"

int	is_number(char c);

int main(int ac, char **av)
{
	game g;

	if (ac != 2 || check_input(av[1]) == 0)
	{
		//print error
		ft_putstr("ERROR");
		return (1);
	}

	/*
	g = init_game(av[1]);;
	if (solve(&g) == 0)
	{
		//print error
		return (1);
	}
	print_game(g);
	*/
	return (0);
}

int check_input(char* input)
{
	int	i;

	i = 0;
	/* 31 = 16 letter && 15 space */
	if (ft_strlen(input) != 31)
		return (0);
	/* find each word in input string */
	while(input[i])
	{
		/* if pair && not number returns 0 */
		if ((i % 2 == 0) && !is_number(input[i]))
				return (0);
		else
		{
			/* if impair && not space returns 0 */
			if (input[i] != 32)
				return (0);
		}
		++i;
	}
	return (1);
}
int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

