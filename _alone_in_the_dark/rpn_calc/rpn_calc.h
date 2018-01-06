/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:54:40 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/06 09:54:42 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALC_H
# define RPN_CALC_H

# include <stdio.h>
# include <stdlib.h>

# define S_SIZE 1000

typedef struct	s_stack
{
	int	index;
	int	stack[S_SIZE];
}		t_stack;

void		reading(char *av, t_stack *s);
void		add_num(char **av, t_stack *s);

#endif
