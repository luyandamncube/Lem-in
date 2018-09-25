/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/25 08:54:24 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start(t_graph *graph, t_stack *stack)
{
	char		**map;

	map = read_map();
	get_bounds(graph, map);
	get_edges(graph, map);
	get_links(graph, map);
	illegal_name(map);
	no_bounds(graph);
	dft(graph, stack, 0);
	if (graph->ants == 0)
	{
		ft_putendl_fd("ERROR: no ants found!", 2);
		exit(1);
	}
	if (has_path(graph) == 0)
	{
		ft_putendl_fd("ERROR: map has no path!", 2);
		exit(1);
	}
	dump_map(map);
	free_map(map);
}

int		main(void)
{
	t_graph		*graph;
	t_stack		*stack;
	t_stack		*path;
	t_stack		*ants;
	int			q[1];

	path = create_stack();
	ants = create_stack();
	stack = create_stack();
	graph = create_graph(8);
	start(graph, stack);
	if (graph->path_size > graph->ants)
		q[0] = graph->ants;
	else
		q[0] = graph->path_size;
	part_1(graph, path, ants, q[0]);
	part_2(graph, path, ants, q[0]);
	part_3(graph, path, ants, q[0]);
	dump_graph(graph);
	free_stack(path);
	free_stack(ants);
	free_all(graph, stack);
	return (0);
}
