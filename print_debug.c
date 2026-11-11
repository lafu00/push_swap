/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_debug.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rehlich <rehlich@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/11 23:25:49 by rehlich          #+#    #+#              */
/*   Updated: 2026/11/11 23:29:38 by rehlich         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_debug(t_stack *stack)
{
	t_node	*curr;
	int		pos;

	if (!stack || !stack->top_a)
	{
		printf("Stack A está vacío.\n");
		return ;
	}
	curr = stack->top_a;
	pos = 0;
	printf("\n--- CONTENIDO DEL STACK A (Tamano: %d) ---\n", stack->size_a);
	while (curr)
	{
		printf("Pos [%d] -> Valor: %d | Indice: %d\n", pos, curr->value, curr->index);
		curr = curr->next;
		pos++;
	}
	printf("------------------------------------------\n\n");
}
