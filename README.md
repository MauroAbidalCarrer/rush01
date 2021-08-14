# rush01

overview:   
1: check inputs If input is incorrect print Error.  
2: initialize game struct.  
3: solve game.   
4: IF could not solve game print Error ELSE print solution. 
   
implementation overview:   
```
struct game
{
	int grid[4][4];//le premier index correspond au colonnes(x), le deuxieme au lignes(y)
	int view_ponits[4][4];
	/*
		first index corresponds to the side:0=up 1=down 2=left 3=right
		second index corresponds to index each side
		examples:
		view_points[0][0] = col1up
		view_points[0][1] = col2up
		view_points[3][0] = col1right
		view_points[1][3] = col3down
	*/
}

int check_input(char* input);//returns 1 if inpu is correct, 0 otherwise

game init_game(char\* input);
//returns the game struct with the view\_points initialized to the input and the grid with every cell initialized to 0

int solve(game *g);
//takes the adrres of the game struct, modifies it and returns 1 ifthe game has been solved, 0 otherwise

void print_game(game g);//prints the gameon the command line, gets called if the previous funcion returns 1.
int main(int ac, char **av)
{
	game g;

	if (ac != 2 || check_input(av[1]) == 0)
	{
		//print error
		return (1);
	}
	g = initialize_game(av[1]);
	if (solve(&g) == 0)
	{
		//print error
		return (1);
	}
	print_game(g);
	return (0);
}
```
