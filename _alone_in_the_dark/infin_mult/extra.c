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

int     numb_init(t_mult *numb, char *s1, char *s2)
{
    char *t1;
    char *t2;

    numb->result = NULL;
    if ((*s1 == '-' && *s2 != '-') ||
            (*s1 != '-' && *s2 == '-'))
        numb->sign = 1;
    else
        numb->sign = 0;
    numb->len_1 = (*s1 == '-' ? ft_strlen(s1) - 1 : ft_strlen(s1));
    numb->len_2 = (*s2 == '-' ? ft_strlen(s2) - 1 : ft_strlen(s2));
    t1 = (*s1 == '-' ? s1 + 1 : s1);
    t2 = (*s2 == '-' ? s2 + 1 : s2);
    numb->rev_num1 = ft_rev(t1);
    numb->rev_num2 = ft_rev(t2);
    return (numb->rev_num1 && numb->rev_num2 ? 1 : 0);
}

int 	*ft_rev(char *s)
{
	int 	i;
    int     len;
	int		*res;

	len = ft_strlen(s);
	if ((res = (int *)malloc(sizeof(int) * len)))
	{
		i = 0;
		while (len >= 0)
			res[i++] = s[--len] - '0';
		return (res);
	}
	return (NULL);
}

int 	ft_strlen(const char *s)
{
	int 	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

void    clean_numb(t_mult *numb)
{
    if (numb->result)
    {
        free(numb->result);
        numb->result = NULL;
    }
    if (numb->rev_num1)
    {
        free(numb->rev_num1);
        numb->rev_num1 = NULL;
    }
    if (numb->rev_num2)
    {
        free(numb->rev_num2);
        numb->rev_num2 = NULL;
    }
}
