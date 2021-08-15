/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:17:00 by kychoi            #+#    #+#             */
/*   Updated: 2021/08/15 12:43:46 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_game	init_game(char *av)
{
	t_game	g;
	int		x;
	int		y;
	int		index;

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
