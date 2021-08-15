/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:41:41 by kychoi            #+#    #+#             */
/*   Updated: 2021/08/15 17:38:32 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define	HEADER_H
# define GAME_SIZE 4

# include <unistd.h>
typedef struct game_s
{
	int	**grid;
	int	**view_points;
	int	size;
}	t_game;

int		check_input(char *input);
t_game	init_game(char *input, int size);
int		*init_input_to_tab(int *tab);
void	init_view_points(char *input, int view_points[][4]);
int		*ft_atoi(char *str, int *res);
/*solve game.*/
int		solve(int x, int y, t_game *g);
/*print game*/
void	print_game(t_game g);
void	print_game_with_view_points(t_game g);
/*usefull*/
int		ft_strlen(char *str);
int		is_number(char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
#endif
