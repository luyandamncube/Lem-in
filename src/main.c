/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/19 15:55:18 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h> //REMOVE ME

void	start(t_graph *graph, t_stack *stack, char **map)
{
	get_bounds(graph, map);
	get_edges(graph, map);
	get_links(graph, map);
	dump_map(map);
	dft(graph, stack, 0);
	dump_graph(graph);
}

int		main(void)
{
	t_graph		*graph;
	t_stack		*stack;
	char		**map;

	stack = create_stack();
	graph = create_graph(8);
	map = read_map();
	start(graph, stack, map);
	free_all(graph, stack, map);
	return (0);
}
