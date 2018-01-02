#include "brackets.h"

int		check_brackets(t_stack *s, char *av)
{
	while (*av)
	{
		if (*av == '(' || *av == '[' || *av == '{')
			s->array[(s->index)++] = *av;
		else if (*av == ')')
		{
			if (--(s->index) < 0 || s->array[s->index] != '(')
				return (0);
		}
		else if (*av == ']')
		{
			if (--(s->index) < 0 || s->array[s->index] != '[')
				return (0);
		}
		else if (*av == '}')
		{
			if (--(s->index) < 0 || s->array[s->index] != '{')
				return (0);
		}
		av++;
	}
	return (s->index == 0 ? (1) : (0));
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	t_stack	s;

	if (argc > 1)
	{
		i = 1;
		j = 0;
		while (i < argc)
		{
			s.index = 0;
			while (j < A_SIZE)
				s.array[j++] = 0;
			if (check_brackets(&s, argv[i++]))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}