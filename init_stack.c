/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   init_stack.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lerodrig <lerodrig@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/11 22:11:53 by lerodrig         #+#    #+#              */
/*   Updated: 2026/11/13 10:50:48 by lerodrig        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. Crea un nodo individual con su valor original y su índice precalculado

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

// 2. Construye el Stack A enlazando ambos arrays (valores e índices)

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

// 3. Inicializa la estructura principal con Stack B vacío y contadores a 0

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
	stack->bench_mode = (flag >= 10);
	stack->strategy = flag % 10;
	stack->disorder = disorder;
	stack->count_op = 0;
	i = -1;
	while (++i < 11)
		stack->stat_op[i] = 0;
	return (stack);
}

// 4. Libera todos los nodos de una lista enlazada

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

// 5. Limpieza total de ambos stacks y la estructura de control

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
