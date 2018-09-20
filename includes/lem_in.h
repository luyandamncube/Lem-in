/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:29:46 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/20 08:57:36 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/stack.h"
# include <stdio.h>

typedef struct		s_node
{
	int				id;
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
	int				path_size;
	int				ants;
	int				has_start;
	int				has_end;
	int				*visited;
	int				*path;
	t_adjlist		*array;
}					t_graph;

char				**read_map();
int					find_id(t_graph *graph, char *name);
int					has_path(t_graph *graph);
void				illegal_name(char **map);
void				illegal_name2(char **map);
void				no_bounds(t_graph *graph);
void				no_path(t_graph *graph);
void				valid_room(char *room);
char				*find_name(t_graph *graph, int id);
void				append(t_adjlist *list, t_node *new_node);
t_node				*create_node(int id, char *name);
t_graph				*create_graph(int n);
t_stack				*create_stack(void);
void				edge(t_graph *graph, char *name);
void				add_link(t_graph *graph, char *dest, char *src);
void				dump_list(t_adjlist list);
void				dump_graph(t_graph *graph);
void				dump_map(char **out);
void				free_map(char **map);
void				free_list(t_adjlist *list);
void				free_graph(t_graph *graph);
void				free_stack(t_stack *stack);
void				free_all(t_graph *graph, t_stack *stack, char **map);
void				get_bounds(t_graph *graph, char **map);
void				get_edges(t_graph *graph, char **map);
void				get_links(t_graph *graph, char **map);
void				dft(t_graph *graph, t_stack *stack, int k);

#endif
