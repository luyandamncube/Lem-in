/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/20 14:56:47 by lmncube          ###   ########.fr       */
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
	dump_graph(graph);
}

int		main(void)
{
	t_graph		*graph;
	t_stack		*stack;
	char		**map;
	int			k;
	int			k_count;
	int			m;

	stack = create_stack();
	graph = create_graph(8);
	map = read_map();
	start(graph, stack, map);
	k = -1;
	while (++k < graph->path_size)
	{
		m = k;
		k_count = k;
		while (m-- > 0)
		{
			
			printf("L%d = %s ", m+1, find_name(graph, graph->path[k_count-- - 1]));
		}
		printf("\n");
	}
	free_all(graph, stack, map);
	return (0);
}
