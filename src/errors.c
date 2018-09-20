/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:52:04 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/20 08:57:18 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				has_path(t_graph *graph)
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
	if (!start_flag || !end_flag)
		return (0);
	return (1);
}

void			illegal_name(char **map)
{
	int		k;

	k = -1;
	while (map[++k])
	{
		if (ft_strchr(map[k], 'L') || ft_strcmp(map[k], "") == 0)
		{
			perror("ERROR");
			exit(1);
		}
		if (ft_strstr(map[k], "##") && ft_strcmp(map[k], "##end") &&
			ft_strcmp(map[k], "##start"))
		{
			perror("ERROR");
			exit(1);
		}
	}
}

void			illegal_name2(char **map)
{
	int	k;

	k = -1;
	while (map[++k])
	{
		if (ft_wordcount(map[k]) == 3 && ft_strchr(map[k], '-'))
		{
			perror("ERROR");
			exit(1);
		}
	}
}

void			no_bounds(t_graph *graph)
{
	if (!graph->has_start || !graph->has_end)
	{
		perror("ERROR\n");
		exit(1);
	}
}

void			valid_room(char *room)
{
	if (ft_wordcount(room) != 3)
	{
		perror("ERROR");
		exit(1);
	}
}
