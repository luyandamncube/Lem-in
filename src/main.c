/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/14 16:29:45 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h> //REMOVE ME

void		DFS(t_graph *graph,	int *visited)
{
	int			k;

	k = graph->start;
	if (graph->array[k].head->id != graph->end)
	{
		while(graph->array[++k].head)
		{
			if (!visited[k])
			{
				visited[k] = 1;
				DFS(graph, visited);
			}
		}
	}	
}

void		DFS_main(t_graph *graph)
{
	int 	visited[10] = {0};
	int		k;

	k = -1;
	visited[graph->start] = 1;
	while(graph->array[++k].head)
		DFS(graph, visited);
	k = -1;
	while (++k < 10)
		printf("elem %d ", visited[k]);
}


int		main(void)
{
	t_graph		*graph;
	graph = create_graph(10);
	edge(graph, "0");
	edge(graph, "1");
	edge(graph, "2");
	edge(graph, "3");
	set_bounds(graph, "0", "3");
	add_link(graph, "0", "1");
	add_link(graph, "0", "2");
	add_link(graph, "1", "2");
	add_link(graph, "2", "0");
	add_link(graph, "2", "3");
	add_link(graph, "3", "3");
	//printf("======= adj list at index 0 ====== \n");
	//dump_list(graph->array[0]);
	printf("======= graph  ====== \n");
	dump_graph(graph);
	printf("\n");
	printf("start %d\n", graph->start);
	printf("end %d \n", graph->end);
	DFS_main(graph);
	free_all(graph);
	return (0);
}
