/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:18:57 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/18 15:41:01 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_map(char **out)
{
	int		k;

	k = -1;
	while (out[++k])
		free(out[k]);
	free(out[k]);
	free(out);
}

void	free_list(t_adjlist *list)
{
	t_node *current;
	t_node *next;

	current = list->head;
	while (current != NULL)
	{
		next = current->next;
		free(current->name);
		free(current);
		current = next;
	}
	list->head = NULL;
}

void	free_graph(t_graph *graph)
{
	int k;

	k = -1;
	while (++k < graph->n + 1)
		free_list(&graph->array[k]);
	free(graph->array);
	free(graph->path);
	free(graph->visited);
	free(graph);
}

void	free_stack(t_stack *stack)
{
	free(stack->s);
	free(stack);
}

void	free_all(t_graph *graph, t_stack *stack, char **map)
{
	free_graph(graph);
	free_stack(stack);
	free_map(map);
}
