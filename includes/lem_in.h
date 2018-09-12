/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:29:46 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/12 14:07:45 by lmncube          ###   ########.fr       */
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

# endif 
