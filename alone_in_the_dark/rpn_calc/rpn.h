/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:54:52 by vlvereta          #+#    #+#             */
/*   Updated: 2017/12/04 09:54:53 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

# include <stdio.h>
# include <stdlib.h>

# define S_SIZE 1000

typedef struct 		s_stack
{
	int				index;
	int				stack[S_SIZE];
}					t_stack;

void				reading(char *av, t_stack *s);
void				add_num(char **av, t_stack *s);

#endif
