#ifndef BRACKETS_H
# define BRACKETS_H

# define A_SIZE 4096

# include <unistd.h>

typedef struct s_stack
{
	char	array[A_SIZE];
	int		index;
}				t_stack;

#endif