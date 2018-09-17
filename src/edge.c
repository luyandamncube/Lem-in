/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:14:26 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/17 13:18:20 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	edge(t_graph *graph, char *name)
{
	t_node	*temp;
	int		k;

	k = -1;
	while (++k < graph->n)
		if (graph->array[k].head == NULL)
		{
			temp = create_node(k, name);
			graph->array[k].head = temp;
			break ;
		}
}

void	add_link(t_graph *graph, char *dest, char *src)
{
	int		k;
	int		id;
	t_node	*new_node;

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
	k = -1;
	while (graph->array[++k].head)
	{
		if (ft_strcmp(src, graph->array[k].head->name) == 0)
		{
			id = find_id(graph, dest);
			new_node = create_node(id, dest);
			append(&graph->array[k], new_node);
		}
	}
}
