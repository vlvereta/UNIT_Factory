/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2017/10/25 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACKETS_H
# define BRACKETS_H

# define A_SIZE 4096

# include <unistd.h>

typedef struct	s_stack
{
	char	array[A_SIZE];
	int	index;
}		t_stack;

#endif
