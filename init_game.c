#include <stdio.h>
#include "header.h"

game	init_game(char *input)
{
	int	i;
	int	j;
	int	input_to_tab[16];
	game	start;

	i = -1;
	j = -1;
	while (++i < GAME_SIZE)
	{
		while (++j < GAME_SIZE)
		{
			start.grid[i][j] = 0;
		}
		j = -1;
	}
	init_view_points(input, start.view_points);
	return (start);
}

int *init_input_to_tab(int *tab)
{
	int	i;

	i = -1;
	while (++i < 16)
		tab[i] = 0;
	return (tab);
}

void init_view_points(char *input, int view_points[][4])
{
	int	input_pov[16];
	int	index_pov;
	int	i;
	int	j;

	init_input_to_tab(input_pov);
	ft_atoi(input, input_pov);
	index_pov = -1;
	i = -1;
	j = -1;
	while (++i < GAME_SIZE)
	{
		while (++j < GAME_SIZE)
		{
			view_points[i][j] = input_pov[++index_pov];
		}
		j = -1;
	}
}

int *ft_atoi(char *str, int *res)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (is_number(str[i]))
			res[j] = res[j] * 10 + str[i] - '0';
		else
			j++;
	}
	return (res);
}
