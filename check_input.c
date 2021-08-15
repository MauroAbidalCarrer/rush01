/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:17:03 by kychoi            #+#    #+#             */
/*   Updated: 2021/08/15 17:32:25 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_input(char *input)
{
	int		i;
	int		size;
	int		len;

	i = 0;
	len = ft_strlen(input);
	size = (len + 1) / 8;
	if (len % 2 == 0)
		return (0);
	if ((len + 1) % 8 != 0)
		return (0);
	while (input[i])
	{
		if (i % 2 == 0)
		{
			if (!is_number(input[i]))
				return (0);
			if (input[i] == '0' || input[i] - 48 > size)
				return (0);
		}
		else if (input[i] != 32)
			return (0);
		++i;
	}
	return (size);
}
