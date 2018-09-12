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

t_graph		*create(int x, int y, int id)
{
	t_graph	*new;

	new = (t_graph*)malloc(sizeof(t_graph));
	new->next = NULL;
	new->x = x;
	new->y = y;
	new->id = id;
	return (new);
}
