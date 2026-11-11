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

satic	void	swap_x(t_node **head)
{
	t_node	*node0;
	t_node	*node1;

	if (!head || !*head || !(*head)->next)
		return ;
	node0 = *head;
	node1 = node0->next;
	node0->next = node1->next;
	if (node1->next)
		node1->next->prev = node0;
	node1->prev = NULL;
	node1->next = node0;
	node0->prev = node1;
	*head = node1;
}

void	sa(t_stack *stack, int silent)
{
	if(stack->size_a < 2)
		return;
	swap(&(stack->stack_a))
	if (!silent)
	{
		write(1, "sa\n", 3);
		stack->count_op++;
		stack->stat_op[0]++;
	}
}

void	sb(t_stack *stack, int silent)
{
	if(stack->size_b < 2)
		return;
	swap(&(stack->stack_b))
	if (!silent)
	{
		write(1, "sb\n", 3);
		stack->count_op++;
		stack->stat_op[1]++;
	}
}

void	ss(t_stack *stack)
{
	int	 executed;

	executed = 0;
	if(stack->size_a > 2)
	{
		sa(stack, 1);
		executed = 1;
	}
	if(stack->size_b > 2)
	{
		sb(stack, 1);
		executed = 1;
	}
	if (executed)
	{
		write(1, "ss\n", 3);
		stack->count_op++;
		stack->stat_op[2]++;
	}
}
