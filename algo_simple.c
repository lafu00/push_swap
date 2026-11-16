/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo_simple.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rehlich <rehlich@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/16 21:33:26 by rehlich          #+#    #+#              */
/*   Updated: 2026/11/16 21:33:26 by rehlich         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_simple(t_stack *stack)
{
	int	i;
	int	size;

	i = 0;
	size = stack->size_a;
	while (i < (size - 3))
	{
		place_min_to_b(stack, i);
		i++;
	}
	sort_3(stack);
	while (stack->size_b > 0)
		pa(stack);
}
