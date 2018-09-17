/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:29:46 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/17 14:38:09 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
# include "../libft/includes/stack.h"

typedef struct		s_node
{
	int				id;
	int				visited;
	char			*name;
	struct s_node	*next;
}					t_node;

typedef struct		s_adjlist
{
	int				n;
	t_node			*head;
}					t_adjlist;

typedef struct		s_graph
{
	int				n;
	int				start;
	int				end;
	t_adjlist		*array;
}					t_graph;

int					find_id(t_graph *graph, char *name);
char				*find_name(t_graph *graph, int id);
void				append(t_adjlist *list, t_node *new_node);
t_node				*create_node(int id, char *name);
t_graph				*create_graph(int n);
t_stack				*create_stack(void);
void				edge(t_graph *graph, char *name);
void				add_link(t_graph *graph, char *dest, char *src);
void				dump_list(t_adjlist list);
void				dump_graph(t_graph *graph);
void				free_list(t_adjlist *list);
void				free_graph(t_graph *graph);
void				free_all(t_graph *graph);
void				set_bounds(t_graph *graph, char *start, char *end);
void				dft(t_graph *graph, t_stack *stack);

#endif
