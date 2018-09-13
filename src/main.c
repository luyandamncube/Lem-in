/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/13 13:15:14 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h> //REMOVE ME

//assumes start is at least first element in graph
void		DFS(t_graph *graph, int start, int *visited)
{
	int	k;

	k = start;
	visited[start] = 1;
	printf("%d \n", start);

	while(graph->array[k].head)
	{
		printf("count %d\n", k);
		if (!visited[k])
		{
			DFS(graph, k, visited);
		}
		k++;
	}	
}

int		main(void)
{
	t_graph		*graph;
	int		visited[10] = {0};
	
	graph = create_graph(10);
	edge(graph, "0");
	edge(graph, "1");
	edge(graph, "2");
	edge(graph, "3");
	add_link(graph, "0", "1");
	add_link(graph, "0", "2");
	add_link(graph, "1", "2");
	add_link(graph, "2", "0");
	add_link(graph, "2", "3");
	add_link(graph, "3", "3");
	printf("======= adj list at index 0 ====== \n");
	dump_list(graph->array[0]);
	printf("======= graph  ====== \n");
	dump_graph(graph);
	DFS(graph,1,visited);
	free_all(graph);
	/*
	   n1 = create_node(0, "789");
	   list->head = n1;
	   graph->array[0] = *list;
	   n2 = create_node(1, "53");
	   append(&list, n2);
	   n3 = create_node(2, "-7");
	   append(&list, n3);
	*/
	return (0);
}
