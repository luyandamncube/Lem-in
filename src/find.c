/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:18:45 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/17 13:24:16 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			find_id(t_graph *graph, char *name)
{
	int k;

	k = -1;
	while (graph->array[++k].head)
		if (ft_strcmp(name, graph->array[k].head->name) == 0)
			return (k);
	return (-1);
}

char		*find_name(t_graph *graph, int id)
{
	int k;

	k = -1;
	while (graph->array[++k].head)
		if (graph->array[k].head->id == id)
			return (graph->array[k].head->name);
	return ("");
}
