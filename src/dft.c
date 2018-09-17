/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:11:35 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/17 14:44:43 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	dft(t_graph *graph, t_stack *stack)
{
    int		visited[10] = {0};
	int		s;
	int		k;
	t_node	*current;

	ft_push(graph->start, stack);
	while (stack->top != 0 && s != graph->end)
	{
		s = ft_pop(stack);
		k = s;
		current = graph->array[k].head;
		if (!visited[s])
		{
			ft_putstr(find_name(graph, s));
			visited[s] = 1;
		}
		while (current)
		{
			if (!visited[current->id])
				ft_push(current->id, stack);
			current = current->next;
		}
	}
}
