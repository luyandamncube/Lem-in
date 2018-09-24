/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:17:01 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/24 16:20:23 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	dump_map(char **out)
{
	int k;

	k = 0;
	while (out[k])
	{
		ft_putstr(out[k]);
		ft_putstr("\n");
		k++;
	}
}

void	dump_list(t_adjlist list)
{
	t_node *current;

	current = list.head;
	while (current)
	{
		ft_putstr(current->name);
		ft_putstr("\t");
		current = current->next;
	}
	ft_putstr("\n");
}

void	dump_graph(t_graph *graph)
{
	int k;

	ft_putstr("============ graph  ============ \n");
	ft_putstr("\npath: ");
	k = -1;
	while (++k < graph->path_size)
	{
		ft_putstr(find_name(graph, graph->path[k]));
		ft_putstr(" ");
	}
	k = -1;
	ft_putstr("\n\n");
	while (graph->array[++k].head)
	{
		if (graph->array[k].head->id == graph->start)
			ft_putstr("start\t");
		else if (graph->array[k].head->id == graph->end)
			ft_putstr("end\t");
		else
			ft_putstr("node\t");
		dump_list(graph->array[k]);
	}
	ft_putstr("\n");
}
