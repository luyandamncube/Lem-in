/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/20 16:46:33 by lmncube          ###   ########.fr       */
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
	int			m_count;
	int			m;

	stack = create_stack();
	graph = create_graph(8);
	map = read_map();
	start(graph, stack, map);
	k = 0;
	while (k < graph->ants)
	{
		m = k;
		k_count = k;
		m_count = 0;
		if (k < graph->path_size + 1)
		{	
			while (m-- > 0)
			{
				m_count++;
				printf("L%d = %s ", m_count, find_name(graph, graph->path[--k_count]));
			}
			printf("\n");
		}
		else
		{
			printf("other\n");
		/*while (m++ < graph->ants)
		{
				printf("L%d = %s ", m+1, find_name(graph, graph->path[k_count-- - 1]));
		}*/
		}
		k++;
	}
	printf("\n");
	free_all(graph, stack, map);
	return (0);
}
