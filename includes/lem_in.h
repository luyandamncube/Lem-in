/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:29:46 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/12 15:12:32 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN
# include "../libft/includes/libft.h"

typedef struct		s_graph
{
	int				id;
	int				x;
	int				y;
	int				visited;
	struct s_graph	*next;
}					t_graph;

void				append(t_graph** head_ref, t_graph *new_node);
t_graph				*create(int x, int y, int id);
void				dump(t_graph *head);
void				del_list(t_graph **head);

# endif 
