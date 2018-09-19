/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:11:35 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/19 11:19:18 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		quick_check(t_node *node, int index)
{
	t_node *current;

	current = node;
	while (current)
	{
		if (index == current->id)
			return (1);
		current = current->next;
	}
	return (0);
}

void	dft(t_graph *graph, t_stack *stack, int k)
{
	t_node *current;

	ft_push(graph->start, stack);
	while (stack->top != 0 && k != graph->end)
	{
		k = ft_pop(stack);
		current = graph->array[k].head;
		if (quick_check(current, graph->end))
		{
			graph->path[graph->path_size++] = k;
			graph->path[graph->path_size++] = graph->end;
			break ;
		}
		if (!graph->visited[k])
		{
			graph->path[graph->path_size++] = k;
			graph->visited[k] = 1;
		}
		while (current)
		{
			if (!graph->visited[current->id])
				ft_push(current->id, stack);
			current = current->next;
		}
	}
}
