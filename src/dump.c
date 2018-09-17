/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:17:01 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/17 15:55:23 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	ft_putstr("\n");
	ft_putstr("graph start: \t");
	ft_putnbr(graph->start);
	ft_putstr("\n");
	ft_putstr("graph end: \t");
	ft_putnbr(graph->end);
	ft_putstr("\nhas_path:\t");
	has_path(graph) ? ft_putstr("yes") : ft_putstr("no");
	ft_putstr("\npath:\t");
	k = -1;
	while (++k < graph->path_size)
		ft_putnbr(graph->path[k]);
	ft_putstr("\n");
	ft_putstr("============ graph  =========== \n");
	ft_putstr("\n");
	k = -1;
	while (graph->array[++k].head)
		dump_list(graph->array[k]);
	ft_putstr("\n");
}
