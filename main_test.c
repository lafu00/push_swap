/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main_test.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lerodrig <lerodrig@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 22:38:55 by lerodrig         #+#    #+#              */
/*   Updated: 2026/11/13 10:36:18 by lerodrig        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // SOLO PARA PRUEBAS - Borrar antes de entregar

static int	count_and_validate(char **total)
{
	int	size;

	if (!total || !total[0])
		return (0);
	if (!is_valid_number(total))
		return (0);
	size = 0;
	while (total[size])
		size++;
	return (size);
}

static int	*fill_and_check(char **total, int size)
{
	int	*temp;
	int	i;
	int	error;

	temp = malloc(sizeof(int)*size);
	if (!temp)
		return (NULL);
	i = 0;
	error = 0;
	while (i < size)
	{
		temp[i] = (int) ft_atol(total[i], &error);
		if (error == 1)
			return (free(temp), NULL);
		i++;
	}
	if (if_duplicates(temp, size))
		return (free(temp), NULL);
	return (temp);
}

static t_stack	*build_program(int *temp, int size, int flag, double disorder)
{
	int		*indexed;
	t_node	*stack_a;
	int		i;

	indexed = calc_index(temp, size);
	if (!indexed)
		return (free(temp), NULL);
	i = 0;
	printf("Flag: %i\n", flag);
	printf("Elementos en el stack: %i\n", size);
	printf("Disorder: %f\n", disorder);
	stack_a = fill_stack_a(temp, indexed, size);
	while (temp[i])
	{
		printf("Total Indice: %i %i\n", temp[i], indexed[i]);
		i++;
	}
	free(temp);
	free(indexed);
	if (!stack_a)
		return (NULL);
	return (init_stack(stack_a, size, flag, disorder));
}

static int	*parse_args(int argc, char **argv, int *size, int *flag)
{
	char	**total;
	int		*temp;

	total = matrix(argc, argv);
	if (!total)
		return (NULL);
	*flag = extract_flags(total);
	*size = count_and_validate(total);
	if (*size == 0 || *flag == -1)
		return (free_matrix(total), NULL);
	temp = fill_and_check(total, *size);
	free_matrix(total);
	return (temp);
}
// Función auxiliar para visualizar ambos stacks lado a lado

static void	print_both_stacks(t_stack *stack, char *action)
{
	t_node	*a;
	t_node	*b;

	a = stack->top_a;
	b = stack->top_b;
	printf("=== DESPUES DE: %s (Size A: %d | Size B: %d) ===\n",
		action, stack->size_a, stack->size_b);
	while (a || b)
	{
		if (a)
		{
			printf("  A: [Val: %-4d | Idx: %-2d]   ", a->value, a->index);
			a = a->next;
		}
		else
			printf("  A: [       VACIO       ]   ");
		if (b)
		{
			printf("B: [Val: %-4d | Idx: %-2d]\n", b->value, b->index);
			b = b->next;
		}
		else
			printf("B: [       VACIO       ]\n");
	}
	printf("--------------------------------------------------\n\n");
}

// Función de simulación que ejecuta una batería de movimientos

static void	test_movements(t_stack *stack)
{
	print_both_stacks(stack, "ESTADO INICIAL");
	sa(stack, 0);
	print_both_stacks(stack, "SA (Intercambia los 2 primeros de A)");
	rra(stack, 0);
	print_both_stacks(stack, "RRA (Rota A al reves)");
	pb(stack);
	pb(stack);
	print_both_stacks(stack, "PB x2 (Mueve 2 elementos de A hacia B)");
	rr(stack);
	print_both_stacks(stack, "RR (Rota A y B hacia arriba a la vez)");
	rrr(stack);
	print_both_stacks(stack, "RRR (Rota A y B al reves)");
	pa(stack);
	print_both_stacks(stack, "PA (Devuelve la cima de B hacia A)");
	printf("Total de operaciones registradas en benchmark: %ld \n\n",
		stack->count_op);
}

int	main(int argc, char **argv)
{
	int		*temp;
	int		size;
	int		flag;
	double	disorder;
	t_stack	*stack;

	setbuf(stdout, NULL);
	// Desactiva el búfer para tus pruebas
	if (argc == 1)
		return (0);
	temp = parse_args(argc, argv, &size, &flag);
	if (!temp)
		return (write(2, "Error\n", 6), 1);
	disorder = calc_disorder(temp, size);
	stack = build_program(temp, size, flag, disorder);
	if (!stack)
		return (write(2, "Error\n", 6), 1);
	test_movements(stack);
	return (free_all(stack), 0);
}
