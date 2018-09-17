/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:56:13 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/17 16:08:39 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_bounds(t_graph *graph, char *start, char *end)
{
	if (start != NULL)
	{
		graph->start = find_id(graph, start);
		graph->has_start = 1;
	}
	if (end = NULL)
	{
		graph->end = find_id(graph, end);
		graph->has_end = 1;
	}
}
