/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2017/10/25 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define R_SIZE 2048

int	func_1(char *source, int i)
{
	int	temp;

	temp = 1;
	while (temp)
	{
		i++;
		if (source[i] == '[')
			temp++;
		if (source[i] == ']')
			temp--;
	}
	return (i);
}

int	func_2 (char *source, int i)
{
	int	temp;

	temp = 1;
	while (temp)
	{
		i--;
		if (source[i] == '[')
			temp--;
		if (source[i] == ']')
			temp++;
	}
	return (i);
}

void	brainfuck(char *source, char *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (source[i])
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
		if (source[i] == '[' && !result[j])
			i = func_1(source, i);
		if (source[i] == ']' && result[j])
			i = func_2(source, i);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	char	result[R_SIZE];

	if (argc > 1)
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
