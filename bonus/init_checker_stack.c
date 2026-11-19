/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checker_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:01:10 by lerodrig          #+#    #+#             */
/*   Updated: 2026/11/19 11:36:48 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_node	*create_node(int value, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*fill_stack_a(int *temp, int *indexed, int size)
{
	t_node	*head;
	t_node	*curr;
	t_node	*new_node;
	int		i;

	head = NULL;
	i = -1;
	while (++i < size)
	{
		new_node = create_node(temp[i], indexed[i]);
		if (!new_node)
			return (free_nodes(head), NULL);
		if (!head)
			head = new_node;
		else
		{
			curr->next = new_node;
			new_node->prev = curr;
		}
		curr = new_node;
	}
	return (head);
}

t_stack	*init_stack(t_node *a, int size, int flag, double disorder)
{
	t_stack	*stack;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (free_nodes(a), NULL);
	stack->top_a = a;
	stack->top_b = NULL;
	stack->size_a = size;
	stack->size_b = 0;
	stack->bench_mode = 10;
	stack->strategy = (flag % 10);
	stack->disorder = disorder;
	stack->count_op = 0;
	i = -1;
	while (++i < 11)
		stack->stat_op[i] = 0;
	return (stack);
}

void	free_nodes(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	free_all(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->top_a)
		free_nodes(stack->top_a);
	if (stack->top_b)
		free_nodes(stack->top_b);
	free(stack);
}
