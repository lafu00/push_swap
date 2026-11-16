/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo_medium.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rehlich <rehlich@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/16 20:48:38 by rehlich          #+#    #+#              */
/*   Updated: 2026/11/16 21:31:31 by rehlich         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int size)
{
	int	aux;

	aux = 1;
	if (size <= 0)
		return (0);
	while (aux * aux <= size)
	{
		if (aux * aux == size)
			return (aux);
		aux++;
	}
	return (aux - 1);
}

static void	fill_b(t_stack *stack, int range)
{
	int	i;

	i = 0;
	while (stack->size_a > 0)
	{
		if (stack->top_a->index <= i)
		{
			pb(stack);
			rb(stack, 0);
			i++;
		}
		else if (stack->top_a->index <= i + range)
		{
			pb(stack);
			i++;
		}
		else
			ra(stack, 0);
	}
}

void	algo_medium(t_stack *stack)
{
	int	range;
	int	pos;

	range = (ft_sqrt(stack->size_a) * 7) / 5;
	fill_b(stack, range);
	while (stack->size_b > 0)
	{
		pos = find_lowest_index(stack->top_b, stack->size_b - 1);
		if (pos <= stack->size_b / 2)
		{
			while (pos-- > 0)
				rb(stack, 0);
		}
		else
		{
			while (pos++ < stack->size_b)
				rrb(stack, 0);
		}
		pa(stack);
	}
}
