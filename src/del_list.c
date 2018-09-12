/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:43:43 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/12 15:13:33 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_list(t_node **head)
{
	t_node *current = *head;
	t_node *next;

	while (current != NULL) 
	{
		next = current->next;
		free(current);
		current = next;
	}
	head = NULL;
}
