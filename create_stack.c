/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 00:10:28 by rehlich           #+#    #+#             */
/*   Updated: 2026/11/10 12:59:51 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_back(t_stack *s, t_node *n)
{
	if (!s->top_a)
	{
		s->top_a = n;
		s->last = n;
	}
	else
	{
		s->last->next = n;
		n->prev = s->last;
		s->last = n;
	}
	s->size_a++;
}

t_stack	*build_stack(int *temp, int *index_array, int size)
{
	t_stack	*s;
	t_node	*n;
	int		i;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top_a = NULL;
	s->top_b = NULL;
	s->last = NULL;
	s->size_a = 0;
	i = 0;
	while (i < size)
	{
		n = new_node(temp[i], index_array[i]);
		if (!n)
			return (free_stack(s), NULL);
		add_back(s, n);
		i++;
	}
	return (s);
}
