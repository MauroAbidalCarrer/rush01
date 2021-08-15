/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:17:00 by kychoi            #+#    #+#             */
/*   Updated: 2021/08/15 16:50:03 by hmechich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_game	init_game(char *av, int size)
{
	t_game	g;
	int		x;
	int		y;
	int		index;
	int		i;

	x = -1;
	g.grid = malloc(size * sizeof(int*));
	g.view_points = malloc (size * sizeof(int*));
	i = -1;
	while (++i < size)
	{
		g.grid[i] = malloc(size * sizeof(int));
		g.view_points[i] = malloc(size * sizeof(int));
	}
	while (++x < size)
	{
		y = -1;
		while (++y < size)
		{
			g.grid[x][y] = 0;
			index = x * (size * 2) + y * 2;
			g.view_points[x][y] = av[index] - '0';
		}
	}
	return (g);
}
