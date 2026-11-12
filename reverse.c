/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rehlich <rehlich@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 11:43:59 by rehlich          #+#    #+#              */
/*   Updated: 2026/11/12 23:34:17 by rehlich         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_node **head)
{
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
}

void	rra(t_stack *stack, int silent)
{
	if (stack->size_a < 2)
		return ;
	reverse(&(stack->top_a));
	if (!silent)
	{
		write(1, "rra\n", 4);
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
		write(1, "rrb\n", 4);
		stack->count_op++;
		stack->stat_op[9]++;
	}
}

void	rrr(t_stack *stack)
{
	int	executed;

	executed = 0;
	if (stack->size_a >= 2)
	{
		rra(stack, 1);
		executed = 1;
	}
	if (stack->size_b >= 2)
	{
		rrb(stack, 1);
		executed = 1;
	}
	if (executed)
	{
		write(1, "rrr\n", 4);
		stack->count_op++;
		stack->stat_op[10]++;
	}
}
