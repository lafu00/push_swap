/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:43:59 by rehlich           #+#    #+#             */
/*   Updated: 2026/11/12 12:50:18 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_node **head)
{
	t_node	*node0;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	node0 = *head;
	last = *head;
	while (last->next)
		last = last->next;
	last->prev = NULL;
	last->next = node0;
	*head = last;
	node0->prev = last;
}

void	rra(t_stack *stack, int silent)
{
	if (stack->size_a < 2)
		return ;
	reverse(&(stack->top_a));
	if (!silent)
	{
		write(1, "rra\n", 3);
		stack->count_op++;
		stack->stat_op[8]++;
	}
}

void	rrb(t_stack *stack, int silent)
{
	if (stack->size_b < 2)
		return ;
	reverse(&(stack->top_b));
	if (!silent)
	{
		write(1, "rrb\n", 3);
		stack->count_op++;
		stack->stat_op[9]++;
	}
}

void	rrr(t_stack *stack)
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
		write(1, "rrr\n", 3);
		stack->count_op++;
		stack->stat_op[10]++;
	}
}
