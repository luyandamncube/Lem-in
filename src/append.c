/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:51:09 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/12 12:55:59 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 	append(t_adjlist **list, t_node *new_node) 
{
	t_node *last = (*list)->head;
	new_node->next = NULL;
	if ((*list)->head == NULL)
	{
		(*list)->head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node; 
} 
