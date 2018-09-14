/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:56:13 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/14 13:58:35 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_bounds(t_graph *graph, char *start, char *end)
{
	graph->start = find_id(graph, start);
	graph->end = find_id(graph, end);
}
