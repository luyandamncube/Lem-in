/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:11:35 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/18 11:14:41 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		quick_check(t_node *node, int index)
{
	t_node *current;
	t_node *head;

	head = (t_node*)malloc(sizeof(t_node));
	current = node;
	ft_memcpy(head, current, 1000);
	while (current)
	{
		if (index == current->id)
		{
			current = head;
			free(head);
			return (1);
		}
		current = current->next;
	}
	current = head;
	free(head);
	return (0);
}

void	dft(t_graph *graph, t_stack *stack)
{
	int		k;

	ft_push(graph->start, stack);
	while (stack->top != 0 && k != graph->end)
	{
		k = ft_pop(stack);
		if (quick_check(graph->array[k].head, graph->end))
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
		while (graph->array[k].head)
		{
			if (!graph->visited[graph->array[k].head->id])
				ft_push(graph->array[k].head->id, stack);
			graph->array[k].head = graph->array[k].head->next;
		}
	}
}
