/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main_flag_stack.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rehlich <rehlich@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/11 22:11:03 by rehlich          #+#    #+#              */
/*   Updated: 2026/11/11 23:14:19 by rehlich         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	int		*temp;
	int		size;
	int		flag;
	double	disorder;
	t_stack	*stack;

	if (argc == 1)
		return (0);
	temp = parse_args(argc, argv, &size, &flag);
	if (!temp)
		return (write(2, "Error\n", 6), 1);
	disorder = calc_disorder(temp, size);
	if (disorder == 0.0)
		return (free(temp), 0);
	stack = build_program(temp, size, flag, disorder);
	if (!stack)
		return (write(2, "Error\n", 6), 1);
	return (free_all(stack), 0);
}
