/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:41:41 by kychoi            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/08/15 17:38:32 by kychoi           ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/08/15 15:54:13 by maabidal         ###   ########.fr       */
=======
/*   Updated: 2021/08/15 16:52:42 by hmechich         ###   ########.fr       */
>>>>>>> 62ff194819df52ea8ee0291c31c4ad41b8ac259a
>>>>>>> ccf7455652c2177681223769406dcdab56c97855
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define	HEADER_H

# include <unistd.h>
typedef struct game_s
{
	int	**grid;
	int	**view_points;
	int	size;
}	t_game;

int		check_input(char *input);
t_game	init_game(char *input, int size);

/*solve game.*/
int		solve(int x, int y, t_game *g);
/*print game*/
void	print_game(t_game g, int size);
void	print_game_with_view_points(t_game g);
/*usefull*/
int		ft_strlen(char *str);
int		is_number(char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
#endif
