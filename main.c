/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:17:34 by kychoi            #+#    #+#             */
/*   Updated: 2021/08/15 20:08:49 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_game	g;
	int		size;

	if (ac != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	size = check_input(av[1]);
	if (size == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	g = init_game(av[1], size);
	if (solve(0, 0, &g) == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	print_game(g, size);
	return (0);
}
