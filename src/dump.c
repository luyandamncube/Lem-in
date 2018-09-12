/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:00:39 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/12 13:59:30 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h> //REMOVE ME
void	dump(t_graph *head)
{
	while (head)
	{
		ft_putstr("node: id");
		ft_putnbr(head->id);
		ft_putstr(" x");
		ft_putnbr(head->x);
		ft_putstr(" y");
		ft_putnbr(head->y);
		ft_putstr("\n");
		head = head->next;
	} 
}
