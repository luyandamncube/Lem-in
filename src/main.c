/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/14 16:29:45 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h> //REMOVE ME

typedef	struct	s_stack
{
	int			*s;
	int			top;
}				t_stack;

void	push(int temp, t_stack *current)
{
	current->s[current->top++] = temp;
}

int	pop(t_stack *current)
{
	current->top--;
	return (current->s[current->top]);
}

void	dump(t_graph *graph, t_stack *current)
{
	int k = -1;
	if(current->top > 0)
	{
		while(++k < current->top)
		{
			ft_putstr(find_name(graph, current->s[k]));
			ft_putstr(" ");
		}
		ft_putstr("\n");
	}
}
/*
   void		DFS(t_graph *graph, int *visited, t_stack *stack)
   {
   }*/

void		DFS_main(char *start, t_graph *graph)
{
	int		visited[10] = {0};
	t_stack		*stack;
	t_node		*current;
	int 		s;
	int		k;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->s = malloc(500);
	push(find_id(graph, start),stack);
	while (stack->top)
	{	
		s = pop(stack);
		if (!visited[s])
		{
			ft_putstr(find_name(graph, s));
			visited[s] = 1;
		}
		k = s;
		current = graph->array[k].head;
		current = current->next;
		while (current)
		{
			if (!visited[current->id])
				push(current->id , stack);
			current = current->next;
		}
	}
	ft_putstr("\n");
}


int		main(void)
{
	t_graph		*graph;

	graph = create_graph(4);
	printf("graph size %d \n", graph->n);
	edge(graph, "0");
	edge(graph, "1");
	edge(graph, "2");
	edge(graph, "3");
	add_link(graph, "0", "1");
	add_link(graph, "0", "2");
	add_link(graph, "1", "2");
	add_link(graph, "2", "0");
	add_link(graph, "2", "3");
	add_link(graph, "3", "3");
	printf("======= graph  ====== \n");
	dump_graph(graph);
	printf("\n");
	DFS_main("2", graph);
	free_all(graph);
	return (0);
}
