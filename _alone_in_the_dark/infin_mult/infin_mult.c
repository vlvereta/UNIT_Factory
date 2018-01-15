/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/12 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

int 	main(int argc, char *argv[])
{
	t_mult	numb;

	if (argc == 3)
    {
        if (numb_init(&numb, argv[1], argv[2]))
        {
            if (result_init(&numb))
            {
                ft_multiply(&numb);
                print_result(&numb);
            }
        }
        clean_numb(&numb);
	}
	write(1, "\n", 1);
	return (0);
}

int    result_init(t_mult *numb)
{
    int     i;

    numb->length = numb->len_1 + numb->len_2 + 1;
    if ((numb->result = (int *)malloc(sizeof(int) * numb->length)))
    {
        i = 0;
        while (i < numb->length)
            numb->result[i++] = 0;
        return (1);
    }
    return (0);
}

void    ft_multiply(t_mult *numb)
{
    int i;
    int j;

    i = 0;
    while (i < numb->len_1)
    {
        j = 0;
        while (j < numb->len_2)
        {
            numb->result[i + j] += numb->rev_num1[i] * numb->rev_num2[j];
            j++;
        }
        i++;
    }
    i = 0;
    while (i + 1 < numb->length)
    {
        numb->result[i + 1] += numb->result[i] / 10;
        numb->result[i++] %= 10;
    }
    while (!numb->result[numb->length] && numb->length)
        numb->length--;
}

void    print_result(t_mult *numb)
{
    char c;

    if (numb->sign && numb->result[0])
        write(1, "-", 1);
    while (numb->length >= 0)
    {
        c = numb->result[numb->length--] + '0';
        write(1, &c, 1);
    }
}
