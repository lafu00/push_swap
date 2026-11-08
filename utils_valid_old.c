/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils_valid.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rehlich <rehlich@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 13:35:11 by rehlich          #+#    #+#              */
/*   Updated: 2026/11/06 21:47:30 by rehlich         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char **matrix)
{
	int	i;
	int	j;

	if (!matrix || !matrix[0])
		return (0);
	i = 0;
	while (matrix[i])
	{
		j = 0;
		if (matrix[i][j] == '-' || matrix[i][j] == '+')
			j++;
		if (!matrix[i][j])
			return (0);
		while (matrix[i][j])
		{
			if (matrix[i][j] < '0' || matrix[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atol(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			return (*error = 1, 0);
		i++;
	}
	return (result * sign);
}

int	if_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
