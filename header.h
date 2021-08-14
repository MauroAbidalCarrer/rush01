#ifndef HEADERFILE_H
#define HEADERFILE_H

#include<unistd.h>
typedef struct game_s
{
	int grid[4][4];
	int view_points[4][4];
} game;


//										check inputs
int check_input(char* input);//returns 1 if inpu is correct, 0 otherwise


//										initialize game struct.
game init_game(char* input);
//returns the game struct with the view\_points initialized to the input and the grid with every cell initialized to 0


//										solve game.
int solve(game *g);
//takes the adrres of the game struct, modifies it and returns 1 ifthe game has been solved, 0 otherwise


//										print game
void print_game(game g);//prints the gameon the command line, gets called if the previous funcion returns 1.


//										usefull
int ft_strlen(char *str);
void ft_putchar(char c);
void ft_putstr(char *str);
#endif
