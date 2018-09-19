/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:17:01 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/19 15:48:23 by lmncube          ###   ########.fr       */
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
	ft_putstr("graph size: \t");
	ft_putnbr(graph->n);
	ft_putstr("\ngraph start: \t");
	ft_putstr(find_name(graph, graph->start));
	ft_putstr("\ngraph end: \t");
	ft_putstr(find_name(graph, graph->end));
	ft_putstr("\nhas_path:\t");
	if (has_path(graph))
		ft_putstr("yes\npath:\t");
	else
		ft_putstr("no\npath:\t");
	k = -1;
	while (++k < graph->path_size)
	{
		ft_putstr(find_name(graph, graph->path[k]));
		ft_putstr(" ");
	}
	ft_putstr("\n\n");
	k = -1;
	while (graph->array[++k].head)
		dump_list(graph->array[k]);
	ft_putstr("\n");
}
