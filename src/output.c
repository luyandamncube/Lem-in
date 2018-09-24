/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:09:22 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/24 15:06:50 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    part_1(t_graph *graph, t_stack *path, t_stack *ants, int LO)
{
	int     q[4];

	q[0] = 0;
	q[3] = 0;
	while (q[0] < LO + 1)
	{
		q[1] = path->top; //path index
		q[2] = 1; //ants index
		ft_push(graph->path[q[0]], path);
		ft_push(q[3]++, ants);
		while (q[1]-- > 0)
		{
			ft_putstr("L");
			ft_putnbr(ants->s[q[2]++]);
			ft_putstr(" = ");
			ft_putstr(find_name(graph, path->s[q[1]]));
			ft_putstr(" ");
		}
		ft_putstr("\n");
		q[0]++;
	}
}

void    part_2(t_graph *graph, t_stack *path, t_stack *ants, int LO, int ABS)
{
	int     q[5];
	
	q[0] = 0;
	q[3] = ants->top;
	graph->path_size == LO ? q[4] = 0: (q[4] = 1);
	while (q[0] < ABS)
	{
		printf("PART 2 \n");

		q[1] = path->top - 1; //path index
		graph->path_size == LO ? q[2] = q[0] + 1: (q[2] = 1); //ants index
		printf("q[2] value %d\n", q[2]);
		ft_push(q[3]++, ants);
		while (q[1]-- > 0)
		{
			ft_putstr("L");
			if (graph->path_size == LO)
				ft_putnbr(ants->s[++q[2]]);
			else
				ft_putnbr(ants->s[q[2]++]); //UNTESTED. TEST with 4 ants, 8 moves
			ft_putstr(" = ");
			ft_putstr(find_name(graph, path->s[q[1] + q[4]]));
			ft_putstr(" ");
		}
		ft_putstr("\n");
		q[0]++;
	}
}

void    part_3(t_graph *graph, t_stack *path, t_stack *ants, int LO)
{
	int     q[5];
	int		weirdmap;

	q[0] = 0;
	q[4] = LO - 1;
	q[3] = ants->s[ants->top - q[4]];
	graph->path_size > LO ? (weirdmap = 1) : (weirdmap = 0);
	while (++q[0] < LO)
	{
		q[1] = q[4]--; //path index
		q[2] = ants->s[q[3]]; //ants index
		graph->path_size > LO ? q[2]-- : q[2];
		while (q[1]-- > 0)
		{
			ft_putstr("L");
			ft_putnbr(ants->s[q[2]++]);
			ft_putstr(" = ");
			ft_putstr(find_name(graph, path->s[q[1] + q[0] + weirdmap]));
			ft_putstr(" ");
		}
		ft_putstr("\n");
		q[3]++;
	}
	free_stack(path);
	free_stack(ants);
}
