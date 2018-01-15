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

#ifndef INFIN_MULT_H
# define INFIN_MULT_H

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

typedef struct	s_mult
{
    int         len_1;
	int 		*rev_num1;
    int         len_2;
	int 		*rev_num2;
    int         sign;
    int         length;
	int 		*result;
}				t_mult;

int		*ft_rev(char *s);
int 	ft_strlen(const char *s);
void    ft_multiply(t_mult *numb);
void    print_result(t_mult *numb);
void    clean_numb(t_mult *numb);
int     numb_init(t_mult *numb, char *s1, char *s2);
int     result_init(t_mult *numb);

#endif
