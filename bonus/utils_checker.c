/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:51:08 by rehlich           #+#    #+#             */
/*   Updated: 2026/11/18 16:59:57 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_bonus(t_stack *stack)
{
	t_node	*curr;

	if (stack->size_b != 0 || !stack->top_a)
		return (0);
	curr = stack->top_a;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	run_mov(t_stack *stack, char *line)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		return (sa(stack, 0), 1);
	if (ft_strncmp(line, "sb\n", 4) == 0)
		return (sb(stack, 0), 1);
	if (ft_strncmp(line, "ss\n", 4) == 0)
		return (ss(stack), 1);
	if (ft_strncmp(line, "pa\n", 4) == 0)
		return (pa(stack), 1);
	if (ft_strncmp(line, "pb\n", 4) == 0)
		return (pb(stack), 1);
	if (ft_strncmp(line, "ra\n", 4) == 0)
		return (ra(stack, 0), 1);
	if (ft_strncmp(line, "rb\n", 4) == 0)
		return (rb(stack, 0), 1);
	if (ft_strncmp(line, "rr\n", 4) == 0)
		return (rr(stack), 1);
	if (ft_strncmp(line, "rra\n", 5) == 0)
		return (rra(stack, 0), 1);
	if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (rrb(stack, 0), 1);
	if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (rrr(stack), 1);
	return (0);
}

int	input_mov(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!run_mov(stack, line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}
