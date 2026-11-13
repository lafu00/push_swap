/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lerodrig <lerodrig@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 11:51:49 by lerodrig         #+#    #+#              */
/*   Updated: 2026/11/13 15:41:45 by lerodrig        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **ori, t_node **dest)
{
	t_node	*temp;

	if (!ori || !*ori)
		return ;
	temp = *ori;
	*ori = temp->next;
	if (*ori)
		(*ori)->prev = NULL;
	temp->prev = NULL;
	temp->next = *dest;
	if (*dest)
		(*dest)->prev = temp;
	*dest = temp;
}

void	pa(t_stack *stack)
{
	if (stack->size_b == 0)
		return ;
	push(&(stack->top_b), &(stack->top_a));
	stack->size_b--;
	stack->size_a++;
	write(1, "pa\n", 3);
	stack->count_op++;
	stack->stat_op[3]++;
}

void	pb(t_stack *stack)
{
	if (stack->size_a == 0)
		return ;
	push(&(stack->top_a), &(stack->top_b));
	stack->size_a--;
	stack->size_b++;
	write(1, "pb\n", 3);
	stack->count_op++;
	stack->stat_op[4]++;
}
