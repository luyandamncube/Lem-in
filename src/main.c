/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/20 08:57:52 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start(t_graph *graph, t_stack *stack, char **map)
{
	get_bounds(graph, map);
	get_edges(graph, map);
	get_links(graph, map);
	illegal_name(map);
	illegal_name2(map);
	no_bounds(graph);
	dft(graph, stack, 0);
	dump_map(map);
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
