/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/12 15:17:07 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
int		main()
{
	t_node *n1;
	t_node *n2;
	t_node *n3;
	t_node *head;

	n1 = create(4, 5,789);
	head = n1;
	n2 = create(9, 19, 53);
	append(&head, n2);
	n3 = create(45, -8, 0);
	append(&head, n3);
	dump(head);
	del_list(&head);
	dump(head);
	return (0);
}
