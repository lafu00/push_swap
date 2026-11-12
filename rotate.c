/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:26:17 by rehlich           #+#    #+#             */
/*   Updated: 2026/11/12 11:41:02 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **head)
{
	t_node	*node0;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	node0 = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = node0->next;
	(*head)->prev = NULL;
	last->next = node0;
	node0->prev = last;
	node0->next = NULL;
}

void	ra(t_stack *stack, int silent)
{
	if (stack->size_a < 2)
		return ;
	rotate(&(stack->top_a));
	if (!silent)
	{
		write(1, "ra\n", 3);
		stack->count_op++;
		stack->stat_op[5]++;
	}
}

void	rb(t_stack *stack, int silent)
{
	if (stack->size_b < 2)
		return ;
	rotate(&(stack->top_b));
	if (!silent)
	{
		write(1, "rb\n", 3);
		stack->count_op++;
		stack->stat_op[6]++;
	}
}

void	rr(t_stack *stack)
{
	int	executed;

	executed = 0;
	if (stack->size_a > 2)
	{
		ra(stack, 1);
		executed = 1;
	}
	if (stack->size_b > 2)
	{
		rb(stack, 1);
		executed = 1;
	}
	if (executed)
	{
		write(1, "rr\n", 3);
		stack->count_op++;
		stack->stat_op[7]++;
	}
}
