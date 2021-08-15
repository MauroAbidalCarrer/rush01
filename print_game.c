/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:17:05 by kychoi            #+#    #+#             */
/*   Updated: 2021/08/15 20:08:20 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_game(t_game g, int size)
{
	int	x;
	int	y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			ft_putchar('0' + g.grid[x][y]);
			if (x != size - 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
