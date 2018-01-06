/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:00:52 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/06 14:03:48 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*write_array(unsigned int number, int base, int size, int sign)
{
	int	i;
	char	temp;
	char	*array;

	if (!(array = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	array[size] = '\0';
	if (sign)
		array[0] = '-';
	if (!number)
		array[--size] = '0';
	while (number)
	{
		array[--size] = ((temp = number % base) > 9 ? 55 + temp :
				'0' + temp);
		number /= base;
	}
	return (array);
}

char	*ft_itoa_base(int value, int base)
{
	int		sign;
	int		size;
	unsigned int	number;

	sign = (value < 0 ? 1 : 0);
	size = (value < 0 || !value ? 1 : 0);
	number = (value < 0 && base == 10 ? -value : value);
	while (value)
	{
		value /= base;
		size++;
	}
	return (write_array(number, base, size, sign));
}
