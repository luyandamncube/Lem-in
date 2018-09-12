/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:06:14 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/12 14:00:41 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node		*create(int x, int y, int id)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new->next = NULL;
	new->x = x;
	new->y = y;
	new->id = id;
	return (new);
}
