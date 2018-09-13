#include "lem_in.h"

void	dump_list(t_adjlist list)
{
	t_node *current;

	current = list.head;
	while (current)
	{
		ft_putstr("id ");
		ft_putnbr(current->id);
		ft_putstr(" name ");
		ft_putstr(current->name);
		ft_putstr("\n");
		current = current->next;
	}
}

void	dump_graph(t_graph *graph)
{
	int k;

	k = -1;
	while (graph->array[++k].head)
		dump_list(graph->array[k]);
}
