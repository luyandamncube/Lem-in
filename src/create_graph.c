#include "lem_in.h"

t_graph	*create_graph(int N)
{
	t_graph *graph;
	int k;

	graph = (t_graph*)malloc(sizeof(t_graph));
	graph->N = N;
	graph->array = (t_adjlist*)malloc(N * sizeof(t_adjlist));
	k = -1;

	while (++k < N)
		graph->array[k].head = NULL;
	return (graph);
}
