/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils_calc.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lerodrig <lerodrig@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 17:24:13 by lerodrig         #+#    #+#              */
/*   Updated: 2026/11/13 17:24:23 by lerodrig        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calc_disorder(int *temp, int size)
{
	int		i;
	int		j;
	long	mistakes;
	long	total_pairs;

	if (size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (temp[i] > temp[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double) mistakes / (double) total_pairs);
}

int	*calc_index(int *temp, int size)
{
	int	*index_array;
	int	i;
	int	j;

	index_array = malloc(sizeof(int)*size);
	if (!index_array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		index_array[i] = 0;
		j = 0;
		while (j < size)
		{
			if (temp[j] < temp[i])
				index_array[i]++;
			j++;
		}
		i++;
	}
	return (index_array);
}
