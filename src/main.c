/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/21 15:41:37 by lmncube          ###   ########.fr       */
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
	if (has_path(graph) == 0 )
	{
		perror("ERROR");
		exit(1);
	}
	dump_map(map);
}

int	main(void)
{
	t_graph		*graph;
	t_stack		*stack;
	t_stack		*path;
	t_stack		*ants;
	int		LO;
	int		ABS;
	char		**map;

	path = create_stack();
	ants = create_stack();
	stack = create_stack();
	graph = create_graph(8);
	map = read_map();
	start(graph, stack, map);
	if (graph->path_size > graph->ants)
		LO = graph->ants;	
	else
		LO = graph->path_size;
	ABS = graph->ants - graph->path_size;
	ABS > 1 ? ABS = ABS : ABS * (-1);
	part_1(graph, path, ants, LO);
	part_2(graph, path, ants, LO, ABS);
	part_3(graph, path, ants, LO);
	dump_graph(graph);
	free_all(graph, stack, map);
	return (0);
}
