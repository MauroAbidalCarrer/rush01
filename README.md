# rush01 bonus

overview:   
1: check inputs If input is incorrect print Error.  
2: initialize game struct.  
3: solve game.   
4: IF could not solve game print Error ELSE print solution. 
   
implementation overview:   
```
struct game
{
	int **grid;//le premier index correspond au colonnes(x), le deuxieme au lignes(y)
	int **view_ponits;
	int size;
}

int check_input(char* input);//returns size of game if input is correct, 0 otherwise

game init_game(char* input, int size);
//returns the game struct with the view\_points initialized to the input and the grid with every cell initialized to 0

int solve(game *g);
//takes the adrres of the game struct, modifies it and returns 1 ifthe game has been solved, 0 otherwise

void print_game(game g);//prints the game on the command line, gets called if the previous funcion returns 1.
int main(int ac, char **av)
{
	game g;
	int	size;

	if (ac != 2)
	{
		//print error
		return (1);
	}
	size = check_input(av[1]);
	if (size == 0)
	{
		//print error
		return (1);
	}
	g = initialize_game(av[1], size);
	if (solve(&g) == 0)
	{
		//print error
		return (1);
	}
	print_game(g);
	return (0);
}
```
