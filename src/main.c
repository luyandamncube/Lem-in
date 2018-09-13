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

int		main(void)
{
	t_graph		*graph;
	
	graph = create_graph(10);
	edge(graph, "789");
	edge(graph, "quirky");
	edge(graph, "nasty");
	add_link(graph, "789", "newboi");
	printf("======= adj list at index 0 ====== \n");
	dump_list(graph->array[0]);
	printf("======= graph  ====== \n");
	dump_graph(graph);
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
