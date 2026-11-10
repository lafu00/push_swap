/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 18:17:49 by rehlich           #+#    #+#             */
/*   Updated: 2026/11/10 12:24:34 by rehlich          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		flag;
	int		size;
	char	**total;
	int		*temp;
	int		i;
	int		*index_array;
	double	disorder;
	t_stack	*stack_a;

	if (argc == 1)
		return (0);
	total = matrix(argc, argv);
	if (!total)
		return (write(2, "Error\n", 6), 1);
	flag = extract_flags(total);
	size = count_and_validate(total);
	if (size == 0 || flag == -1)
		return (free_matrix(total), write(2, "Error\n", 6), 1);
	temp = fill_and_check(total, size);
	if (!temp)
		return (free_matrix(total), write(2, "Error\n", 6), 1);
	disorder = calc_disorder(temp, size);
	if (disorder == 0.0)
	{
		free(temp);
		free_matrix(total);
		return (0);
	}
	index_array = calc_index(temp, size);
	if (!index_array)
		return (free(temp), free_matrix(total), write(2, "Error\n", 6), 1);
	stack_a = build_stack(temp, index_array, size);
	if (!stack_a)
		return (free(index_array), free(temp), free_matrix(total), write(2, "Error\n", 6), 1);
	i = 0;
	printf("Flag: %i\n", flag);
	printf("Elementos en el stack: %i\n", size);
	printf("Disorder: %f\n", disorder);
	while (total[i])
	{
		printf("Total Indice: %s %i\n", total[i], index_array[i]);
		i++;
	}
	free(index_array);
	free(temp);
	free_matrix(total);
	return (0);
}
