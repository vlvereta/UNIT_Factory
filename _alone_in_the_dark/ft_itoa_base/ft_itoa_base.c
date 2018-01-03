/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:00:52 by vlvereta          #+#    #+#             */
/*   Updated: 2017/11/05 14:03:48 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*write_array(unsigned int number, int base, unsigned int size, int sign)
{
	int		i;
	char	*array;

	array = (char *)malloc(sizeof(char) * (size + 1));
	array[size] = '\0';
	if (sign)
		array[0] = '-';
	if (!number)
		array[--size] = '0';
	while (number)
	{
		if ((number % base) > 9)
			array[--size] = 55 + number % base;
		else
			array[--size] = '0' + number % base;
		number /= base;
	}
	return (array);
}


char	*ft_itoa_base(int value, int base)
{
	int				sign;
	unsigned int	number;
	unsigned int	size;

	size = 0;
	sign = 0;
	if (!value)
		size++;
	if (value < 0 && base == 10)
	{
		number = value * -1;
		sign = 1;
		size++;
	}
	else
		number = value;
	while (value)
	{
		value /= base;
		size++;
	}
	return (write_array(number, base, size, sign));
}

int		main(void)
{
	printf("%s\n", ft_itoa_base(-2147483648, 16));
	printf("%s\n", ft_itoa_base(2147483647, 8));
	printf("%s\n", ft_itoa_base(0, 2));
	return (0);
}
