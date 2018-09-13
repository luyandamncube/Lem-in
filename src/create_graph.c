/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:10:18 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/13 13:11:41 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graph		*create_graph(int n)
{
	t_graph		*graph;
	int			k;

	graph = (t_graph*)malloc(sizeof(t_graph));
	graph->n = n;
	graph->array = (t_adjlist*)malloc(N * sizeof(t_adjlist));
	k = -1;
	while (++k < n)
		graph->array[k].head = NULL;
	return (graph);
}
