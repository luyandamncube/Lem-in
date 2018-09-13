/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:29:46 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/13 13:03:28 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"

typedef struct		s_node
{
	int				id;
	int				visited;
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
	t_adjlist		*array;
}					t_graph;

void				append(t_adjlist **list, t_node *new_node);
t_node				*create_node(int id);
t_graph				*create_graph(int n);
void				dump(t_node *head);
void				del_list(t_node **head);

#endif
