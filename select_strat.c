/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   select_strat.c                                     :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: rehlich <rehlich@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 20:01:11 by rehlich          #+#    #+#              */
/*   Updated: 2026/11/17 11:25:09 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top_a->index;
	second = stack->top_a->next->index;
	third = stack->top_a->next->next->index;
	if (first > second && first > third && second > third)
	{
		sa(stack, 0);
		rra(stack, 0);
	}
	else if (first > second && first > third && second < third)
		ra(stack, 0);
	else if (first > second && first < third && second < third)
		sa(stack, 0);
	if (first < second && first > third && second > third)
		rra(stack, 0);
	if (first < second && second > third && first < third)
	{
		rra(stack, 0);
		sa(stack, 0);
	}
}

int	find_lowest_index(t_node *node, int index)
{
	int	pos;

	pos = 0;
	while (node)
	{
		if (node->index == index)
			return (pos);
		pos++;
		node = node->next;
	}
	return (-1);
}

void	place_min_to_b(t_stack *stack, int index)
{
	int	pos;

	pos = find_lowest_index(stack->top_a, index);
	if (pos < (stack->size_a / 2))
	{
		while (stack->top_a->index != index)
			ra(stack, 0);
	}
	else
	{
		while (stack->top_a->index != index)
			rra(stack, 0);
	}
	pb(stack);
}

void	sort_5(t_stack *stack)
{
	place_min_to_b(stack, 0);
	if (stack->size_a == 4)
		place_min_to_b(stack, 1);
	sort_3(stack);
	pa(stack);
	if (stack->size_b > 0)
		pa(stack);
}

void	select_strat(t_stack *stack)
{
	if (!stack || stack->size_a <= 1 || stack->disorder == 0)
		return ;
	if (stack->size_a == 2)
		printf("run sa\n");
	else if (stack->size_a == 3)
		sort_3(stack);
	else if (stack->size_a <= 5)
		sort_5(stack);
	else if (stack->strategy == 1)
	{
		algo_simple(stack),
		printf("run sort simple O(n2)\n");
	}
	else if (stack->strategy == 2)
	{
		algo_medium(stack);
		printf("run sort medium O(n_sqrt_n)\n");
	}
	else if (stack->strategy == 3)
		printf("run sort complex O(n_Log_n)\n");
	else
	{
		printf("run sort adaptative\n");
		if (stack->size_a > 5 && stack->disorder < 0.2)
		{
			algo_simple(stack);
			printf("run sort simple\n");
		}
		else if (stack->size_a > 5 && stack->disorder >= 0.2
			&& stack->disorder < 0.5)
		{
			algo_medium(stack);
			printf("run sort medium\n");
		}
		else
		{
			algo_complex(stack);
			printf("run sort complex\n");
		}
	}
}
