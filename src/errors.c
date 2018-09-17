/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:52:04 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/17 16:11:18 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			has_path(t_graph *graph)
{
	int		k;
	int		start_flag;
	int		end_flag;

	k = -1;
	start_flag = 0;
	end_flag = 0;
	while (++k < graph->path_size)
	{
		if (graph->path[k] == graph->start)
			start_flag = 1;
		if (graph->path[k] == graph->end)
			end_flag = 1;
	}
	if (!start_flag || !end_flag || !graph->has_start || !graph->has_end)
		return (0);
	return (1);
}
