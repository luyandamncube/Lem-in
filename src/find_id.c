/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:48:06 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/14 12:05:52 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_id(t_graph * graph, char *name)
{
	int k;

	k = -1;
	while (graph->array[++k].head)
		if (ft_strcmp(name, graph->array[k].head->name) == 0)
			return (k);
	return (-1);
}
