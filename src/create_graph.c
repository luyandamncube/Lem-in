/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:10:18 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/14 13:54:15 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h> //REMOVE ME
t_graph		*create_graph(int n)
{
	t_graph		*graph;
	int			k;

	k = -1;
	graph = (t_graph*)malloc(sizeof(t_graph));
	graph->n = n;
	graph->array = (t_adjlist*)malloc((n + 1) * sizeof(t_adjlist));
	while (++k < n + 1)
		graph->array[k].head = NULL;
	return (graph);
}
