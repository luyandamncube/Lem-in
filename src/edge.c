/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:14:26 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/24 15:52:44 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	bastard_node(int flag)
{
	if (flag != 2)
	{
		ft_putendl_fd("ERROR: bastard node found!", 2);
		exit(1);
	}
}

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
	int		q[3];
	t_node	*new_node;

	q[0] = -1;
	q[2] = 0;
	while (graph->array[++q[0]].head)
		if (ft_strcmp(dest, graph->array[q[0]].head->name) == 0)
		{
			q[1] = find_id(graph, src);
			new_node = create_node(q[1], src);
			append(&graph->array[q[0]], new_node);
			q[2]++;
		}
	q[0] = -1;
	while (graph->array[++q[0]].head)
		if (ft_strcmp(src, graph->array[q[0]].head->name) == 0)
		{
			q[1] = find_id(graph, dest);
			new_node = create_node(q[1], dest);
			append(&graph->array[q[0]], new_node);
			q[2]++;
		}
	bastard_node(q[2]);
}
