/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:11:35 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/17 15:20:07 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	dft(t_graph *graph, t_stack *stack)
{
	int		visited[4096];
	int		s;
	int		m;
	t_node	*current;

	m = -1;
	while (++m < graph->n)
		visited[m] = 0;
	ft_push(graph->start, stack);
	while (stack->top != 0 && s != graph->end)
	{
		s = ft_pop(stack);
		current = graph->array[s].head;
		if (!visited[s])
		{
			graph->path[graph->path_size++] = s;
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
