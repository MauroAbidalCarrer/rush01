/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:17:03 by kychoi            #+#    #+#             */
/*   Updated: 2021/08/15 12:17:04 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_input(char *input)
{
	int		i;

	i = 0;
	if (ft_strlen(input) != 31)
		return (0);
	while (input[i])
	{
		if (i % 2 == 0)
		{
			if (!is_number(input[i]))
				return (0);
			if ((input[i] - 48) > 4 || (input[i] - 48) < 1)
				return (0);
		}
		else if (input[i] != 32)
			return (0);
		++i;
	}
	return (1);
}
