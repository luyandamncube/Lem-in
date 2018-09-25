/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:09:22 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/25 09:04:27 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		abs_(int a, int b)
{
	if ((a - b) < 0)
		return (b - a);
	else
		return (a - b);
}

void	part_1(t_graph *graph, t_stack *path, t_stack *ants, int lo)
{
	int	q[4];

	q[0] = 0;
	q[3] = 0;
	while (q[0] < lo + 1)
	{
		q[1] = path->top;
		q[2] = 1;
		ft_push(graph->path[q[0]], path);
		ft_push(q[3]++, ants);
		while (q[1]-- > 0)
		{
			ft_putstr("L");
			ft_putnbr(ants->s[q[2]++]);
			ft_putstr("-");
			ft_putstr(find_name(graph, path->s[q[1]]));
			ft_putstr(" ");
		}
		ft_putstr("\n");
		q[0]++;
	}
}

void	part_2(t_graph *graph, t_stack *path, t_stack *ants, int lo)
{
	int	q[6];

	q[0] = 0;
	q[3] = ants->top;
	q[4] = 0;
	q[5] = abs_(graph->ants, graph->path_size);
	graph->path_size == lo ? q[4] : q[4]++;
	while (q[0] < q[5])
	{
		q[1] = path->top - 1;
		q[2] = (graph->path_size == lo) ? q[0] + 1 : 1;
		ft_push(q[3]++, ants);
		while (q[1]-- > 0)
		{
			ft_putstr("L");
			(graph->path_size == lo) ? ft_putnbr(ants->s[++q[2]])
				: ft_putnbr(ants->s[q[2]++]);
			ft_putstr("-");
			ft_putstr(find_name(graph, path->s[q[1] + q[4]]));
			ft_putstr(" ");
		}
		ft_putstr("\n");
		q[0]++;
	}
}

void	part_3(t_graph *graph, t_stack *path, t_stack *ants, int lo)
{
	int	q[6];

	q[0] = 0;
	q[5] = 0;
	q[4] = lo - 1;
	q[3] = ants->s[ants->top - q[4]];
	graph->path_size > lo ? q[5]++ : q[5];
	while (++q[0] < lo)
	{
		q[1] = q[4]--;
		q[2] = ants->s[q[3]];
		graph->path_size > lo ? q[2]-- : q[2];
		while (q[1]-- > 0)
		{
			ft_putstr("L");
			ft_putnbr(ants->s[q[2]++]);
			ft_putstr("-");
			ft_putstr(find_name(graph, path->s[q[1] + q[0] + q[5]]));
			ft_putstr(" ");
		}
		ft_putstr("\n");
		q[3]++;
	}
}
