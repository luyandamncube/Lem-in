/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:20:03 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/19 16:12:09 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**read_map()
{
	char		**map;
	char		*ret;
	int         k;
	int			fd;

	k = 0;
	fd = 0;
	map = (char**)malloc(sizeof(char*) * 2000);
	while (get_next_line(fd, &ret))
	{
		map[k++] = ft_strdup(ret);
		free(ret);
	}
	free(ret);
	return (map);
}

char	*get_name(char *str, int c)
{
	int		ws_index;
	int		k;

	ws_index = 0;
	k = 0;
	str = ft_strtrim(str);
	while (str[k++] != c)
		ws_index++;
	return (ft_strsub(str, 0, ws_index));
}

void	get_bounds(t_graph *graph, char **map)
{
	int	k;

	k = -1;
	while (map[++k])
	{
		if (ft_strcmp(map[k], "##start") == 0)
		{
			valid_room(map[k + 1]);
			edge(graph, get_name(map[k + 1], ' '));
			graph->has_start = 1;
			graph->start = 0;
		}
		if (ft_strcmp(map[k], "##end") == 0)
		{
			valid_room(map[k + 1]);
			edge(graph, get_name(map[k + 1], ' '));
			graph->has_end = 1;
			graph->end = 1;
		}
	}
}

void	get_edges(t_graph *graph, char **map)
{
	int	k;

	k = -1;
	while (map[++k])
	{
		if (ft_wordcount(map[k]) == 3 &&
			ft_strcmp(get_name(map[k], ' '), find_name(graph, graph->start)) &&
			ft_strcmp(get_name(map[k], ' '), find_name(graph, graph->end)))
		{
			printf("count %d\n", ft_wordcount(map[k]));
			edge(graph, get_name(map[k], ' '));
		}
	}
}

void	get_links(t_graph *graph, char **map)
{
	int		k;
	char	*dash;

	k = -1;
	while (map[++k])
	{
		if (ft_wordcount(map[k]) == 1 && ft_strchr(map[k], '-'))
		{
			dash = ft_strchr(map[k], '-');
			dash++;
			add_link(graph, get_name(map[k], '-'), dash);
		}
	}
}
