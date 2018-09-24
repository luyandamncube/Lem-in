/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/24 13:58:49 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		abs_(int a, int b)
{
	if ((a - b) < 0)
		return (b - a);
	else
		return (a - b);
}

void	start(t_graph *graph, t_stack *stack, char **map)
{
	get_bounds(graph, map);
	get_edges(graph, map);
	get_links(graph, map);
	illegal_name(map);
	//illegal_name2(map);
	no_bounds(graph);
	dft(graph, stack, 0);
	if (graph->ants == 0)
	{
		ft_putendl_fd("ERROR: no ants found!", 2);
		exit(1);
	}	
	if (has_path(graph) == 0 )
	{
		ft_putendl_fd("ERROR: map has no path!", 2);
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
	int			LO;
	int			ABS;
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
	printf("LO %D\n", LO);
	ABS = abs_(graph->ants, graph->path_size);
	part_1(graph, path, ants, LO);
	part_2(graph, path, ants, LO, ABS);
	part_3(graph, path, ants, LO);
	dump_graph(graph);
	free_all(graph, stack, map);
	return (0);
}
