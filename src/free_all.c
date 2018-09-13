#include "lem_in.h"

void	free_list(t_adjlist *list)
{
	t_node *current;
	t_node *next;

	current = list->head;
	while (current != NULL)
	{
		next = current->next;
		free(current->name);
		free(current);
		current = next;
	}
	list->head = NULL;
}

void	free_graph(t_graph *graph)
{
	int k;

	k = -1;
	while (++k < graph->n)
		free_list(&graph->array[k]);
	free(graph->array);
	free(graph);
}

void	free_all(t_graph *graph)
{
	free_graph(graph);
}
