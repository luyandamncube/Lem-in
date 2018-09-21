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
	dump_graph(graph);
}

int		main(void)
{
	t_graph		*graph;
	t_stack		*stack;
	char		**map;
	int			q[10];

	stack = create_stack();
	graph = create_graph(8);
	map = read_map();
	start(graph, stack, map);
	q[0] = 0;
	q[7] = 1;
	while (q[0] < (graph->ants + graph->ants/2))
	{
		if (q[0] < graph->path_size)
		{	
			q[1] = q[0] + 1;
			q[2] = q[0];
			q[3] = 1;
			while (q[1]-- > 0)
			{
				printf("L%d = %s ", q[3], find_name(graph, graph->path[q[2]--]));
				q[3]++;
			}
			printf("\n");
		}
		else
		{
			q[6] = graph->ants - q[0] + q[7] - 1; //controls number of maxim moves at a time
			q[7]++;
			q[8] = q[7];
			q[9] = graph->path_size - 1; //controls index of move. starts at end of path_size
			q[5] = 0;
			while (q[5]++ < q[6] && q[8] < graph->ants + 1)
			{
				printf("L%d = %s ", q[8]++, find_name(graph, graph->path[q[9]--]));
				q[3]++;
			}
			printf("\n");
		}
		q[0]++;
	}
	printf("\n");
	free_all(graph, stack, map);
	return (0);
}
