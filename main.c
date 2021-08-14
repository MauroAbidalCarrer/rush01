#include <stdio.h>

int	ft_char_is_numeric(char c);
int	main(int ac, char **av)
{
	int	count;
	int	good_format;
	int	i;

	count = 0;
	i = -1;
	good_format = 1;
	if (ac == 2)
	{
		while (av[1][++i])
		{
			if (!ft_char_is_numeric(av[1][i]))
			{
				if (av[1][i] == ' ')
					count++;
				else
				{
					good_format = 0;
					break ;
				}
			}
		}
		if (good_format && count == 15)
			printf("OK");
		//	resolve_puzzle();
		else
			printf("NO");
	}
}

int	ft_char_is_numeric(char c)
{
	int	is_num;

	is_num = 1;
	if (c < '0' || c > '9')
	{
		is_num = 0;
	}
	return (is_num);
}
