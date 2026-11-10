/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:17:57 by rehlich           #+#    #+#             */
/*   Updated: 2026/11/10 12:29:15 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_x(t_node **stack)
{
	t_node	*node0;
	t_node	*node1;

	if (!stack || !*stack || !(stack)->next)
		return ;
	node0 = *stack;
	node1 = node0->next;
	node0->next = node1->next;
	node1->next = node0;
	*stack = node1;
}
