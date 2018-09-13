/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/13 13:15:14 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_node		*n1;
	t_node		*n2;
	t_node		*n3;
	t_adjlist	*list;
	t_graph		*graph;

	list = malloc(sizeof(t_adjlist));
	n1 = create_node(789);
	list->head = n1;
	n2 = create_node(53);
	append(&list, n2);
	n3 = create_node(0);
	append(&list, n3);
	dump(list->head);
	del_list(&list->head);
	free(list);
	return (0);
}
