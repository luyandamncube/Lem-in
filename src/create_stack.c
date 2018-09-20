/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:29:32 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/20 09:01:05 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_stack		*create_stack(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->s = malloc(4096);
	stack->top = 0;
	return (stack);
}
