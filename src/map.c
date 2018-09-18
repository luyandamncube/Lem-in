/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:20:03 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/18 16:13:11 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**read_map(int fd, char **ret)
{
	char	**map;
	int		k;

	k = -1;
	map = (char **)malloc(sizeof(char*) * 4096);
	while (++k < 4096)
		map[k] = (char *)malloc(sizeof(char) *4096);
	k = -1;
	while (get_next_line(fd, ret))
		ft_memcpy(map[++k], *ret, 4096);
	map[++k] = NULL;
	return (map);
}

void	get_info(t_graph * graph, char **map)
{
	int	k;

	k = -1;
	while (map[++k])
	{
		if (ft_strcmp(map[k], "##start") == 0)
		{
			edge(graph, map[k + 1]);
			graph->start = find_id(graph, map[k + 1]);
		}	
	}
}
