/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/18 16:07:31 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>


int		main(void)
{
	t_graph		*graph;
	t_stack		*stack;
	char		*ret;
	char 		**map;

	map = read_map(0, &ret); 
	stack = create_stack();
	graph = create_graph(8);
	dump_map(map);
	edge(graph, "0");
	edge(graph, "1");
	edge(graph, "2");
	edge(graph, "3");
	edge(graph, "4");
	edge(graph, "5");
	edge(graph, "6");
	edge(graph, "7");
	add_link(graph, "0", "4");
	add_link(graph, "0", "6");
	add_link(graph, "1", "3");
	add_link(graph, "4", "3");
	add_link(graph, "5", "2");
	add_link(graph, "3", "5");
	add_link(graph, "4", "2");
	add_link(graph, "2", "1");
	add_link(graph, "7", "6");
	add_link(graph, "7", "2");
	add_link(graph, "7", "4");
	add_link(graph, "6", "5");
	set_bounds(graph, "0", "4");
	dft(graph, stack);
	dump_graph(graph);
	free_all(graph, stack, map);
	return (0);
}
