/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:10:18 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/20 09:01:53 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graph		*create_graph(int n)
{
	t_graph		*graph;
	int			k;

	graph = (t_graph*)malloc(sizeof(t_graph));
	graph->n = n;
	graph->start = 0;
	graph->end = 0;
	graph->has_start = 0;
	graph->has_end = 0;
	graph->path_size = 0;
	graph->ants = 0;
	graph->array = (t_adjlist*)malloc((n + 1) * sizeof(t_adjlist));
	graph->path = malloc(4096);
	graph->visited = malloc(4096);
	k = -1;
	while (++k < n + 1)
		graph->array[k].head = NULL;
	return (graph);
}
