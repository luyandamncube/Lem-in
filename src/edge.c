#include "lem_in.h"

int	find_id(t_graph * graph, char *name)
{
	int k;

	k = -1;
	while (graph->array[++k].head)
		if (ft_strcmp(name, graph->array[k].head->name) == 0)
			return (k);
	return (-1);
}

void    edge(t_graph *graph, char *name)
{
	t_node          *temp;
	int             k;

	k = -1;
	while (++k < graph->n)
		if (graph->array[k].head == NULL)
		{
			temp = create_node(k, name);
			graph->array[k].head = temp;
			break ;
		}
}

void	add_link(t_graph *graph, const char *dest, char *src)
{
	int k;
	int id;
	t_node *new_node;

	k = -1;
	while (graph->array[++k].head)
	{
		if (ft_strcmp(dest, graph->array[k].head->name) == 0)
		{
			id = find_id(graph, src);
			new_node = create_node(id, src);
			append(&graph->array[k], new_node);
		}
	}
}
