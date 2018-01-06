/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:54:40 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/06 09:54:42 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

int		main(int argc, char *argv[])
{
	int	i;
	t_stack	s;

	if (argc == 2)
	{
		i = 0;
		while (i < S_SIZE)
			s.stack[i++] = 0;
		s.index = -1;
		reading(argv[1], &s);
	}
	else
		printf("Error\n");
	return (0);
}

void		reading(char *av, t_stack *s)
{
	while (*av)
	{
		if (*av >= '0' && *av <= '9')
			add_num(&av, s);
		else if (*av == '-' && *(av + 1) >= '0' && *(av + 1) <= '9')
			add_num(&av, s);
		else if (*av == '+' && --(s->index) >= 0)
			s->stack[s->index] = s->stack[s->index] + s->stack[s->index + 1];
		else if (*av == '-' && --(s->index) >= 0)
			s->stack[s->index] = s->stack[s->index] - s->stack[s->index + 1];
		else if (*av == '*' && --(s->index) >= 0)
			s->stack[s->index] = s->stack[s->index] * s->stack[s->index + 1];
		else if (*av == '/' && s->stack[s->index] && --(s->index) >= 0)
			s->stack[s->index] = s->stack[s->index] / s->stack[s->index + 1];
		else if (*av == '%' && s->stack[s->index] && --(s->index) >= 0)
			s->stack[s->index] = s->stack[s->index] % s->stack[s->index + 1];
		else if (*av != ' ')
			break ;
		av++;
	}
	if (!(*av) && !(s->index))
		printf("%d\n", s->stack[s->index]);
	else
		printf("Error\n");
}

void		add_num(char **av, t_stack *s)
{
	int	i;
	char	*temp;

	if ((temp = (char *)malloc(sizeof(char) * 12)))
	{
		i = 0;
		if (*(*av) == '-')
			temp[i++] = *(*av)++;
		while(*(*av) >= '0' && *(*av) <= '9')
			temp[i++] = *(*av)++;
		temp[i] = '\0';
		s->stack[++(s->index)] = atoi(temp);
		free(temp);
	}
}
