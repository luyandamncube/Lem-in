/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:12:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/12 14:06:04 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
int		main()
{

	t_graph *n1;
	t_graph *n2;
	t_graph *n3;
	t_graph *head;

	n1 = create(4, 5,789);
	head = n1;
	n2 = create(9, 19, 53);
	append(&head, n2);
	n3 = create(45, -8, 0);
	append(&head, n3);
	dump(head);
	return (0);
}
