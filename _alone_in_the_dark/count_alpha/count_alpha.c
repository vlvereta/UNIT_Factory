/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/07 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define L_AMOUNT 26

typedef struct	s_lcounter
{
	int	amount[L_AMOUNT];
	char	letter[L_AMOUNT];
	char	*input;
}		t_lcounter;

void		counter_init(t_lcounter *counter)
{
	int	i;

	i = 0;
	while (i < L_AMOUNT)
		counter->amount[i++] = 0;
	i = 0;
	while (i < L_AMOUNT)
		counter->letter[i++] = '\0';
}

void		count_letters(t_lcounter *counter)
{
	int	i;
	int	j;
	char	temp;

	i = 0;
	while (counter->input[i])
	{
		temp = (counter->input[i] >= 'A' && counter->input[i] <= 'Z' ?
				counter->input[i] + 32 : '\0');
		temp = (counter->input[i] >= 'a' && counter->input[i] <= 'z' ?
				counter->input[i] : '\0');
		j = 0;
		while (temp && j < L_AMOUNT)
		{
			if (temp == counter->letter[j] || !counter->letter[j])
			{
				counter->letter[j] = temp;
				counter->amount[j]++;
				break ;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	t_lcounter	counter;

	if (argc == 2)
	{
		counter.input = argv[1];
		counter_init(&counter);
		count_letters(&counter);
		i = 0;
		while (i < L_AMOUNT)
		{
			if (counter.letter[i])
				printf("%d%c", counter.amount[i], counter.letter[i]);
			if (++i != L_AMOUNT && counter.letter[i])
				printf(", ");
			else
				break ;
		}
	}
	printf("\n");
	return (0);
}
