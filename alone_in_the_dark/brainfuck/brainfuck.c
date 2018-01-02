#include <unistd.h>
#include <stdlib.h>

#define R_SIZE 2048

// int		func_2(char *source, int i)
// {
// 	int	temp;

// 	temp = 1;
// 	while (temp)
// 	{
// 		--i;
// 		if (source[i] == '[')
// 			temp--;
// 		if (source[i] == ']')
// 			temp++;
// 	}
// 	--i;
// 	return (i);
// }

// int		func_1(char *source, int i)
// {
// 	int	temp;

// 	temp = 1;
// 	while (temp)
// 	{
// 		++i;
// 		if (source[i] == ']')
// 			temp--;
// 		if (source[i] == '[')
// 			temp++;
// 	}
// 	return (i);
// }

void	brainfuck(char *source, char *result)
{
	int	temp;
	int	j = 0;

	for (int i = 0; source[i]; i++)
	{
		if (source[i] == '>')
			j++;
		if (source[i] == '<')
			j--;
		if (source[i] == '+')
			(result[j])++;
		if (source[i] == '-')
			(result[j])--;
		if (source[i] == '.')
			write(1, &(result[j]), 1);
		if (source[i] == '[')
		{
			if (!result[j])
			{
				int temp = 1;
				while (temp)
				{
					++i;
					if (source[i] == '[')
						++temp;
					if (source[i] == ']')
						--temp;
				}
			}
			else
				continue ;
		}
		else if (source[j] == ']')
		{
			if (!result[j])
				continue ;
			else
			{
				if (source[i] == ']')
					temp++;
				while (temp)
				{
					--i;
					if (source[i] == '[')
						temp--;
					if (source[i] == ']')
						temp++;
				}
				--i;
			}
		}
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	char	result[R_SIZE];

	if (argc == 2)
	{
		i = 0;
		while (i < R_SIZE)
			result[i++] = 0;
		brainfuck(argv[1], result);
	}
	else
		write(1, "\n", 1);
	return (0);
}