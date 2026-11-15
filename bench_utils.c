/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 21:55:46 by lerodrig          #+#    #+#             */
/*   Updated: 2026/11/15 21:56:28 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	disorder_level(double disorder)
{
	if (disorder < 0.2)
		return (0);
	if (disorder < 0.5)
		return (1);
	return (2);
}

void	print_disorder(double disorder)
{
	long	hundredths;

	hundredths = (long)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(hundredths / 100), 2);
	ft_putchar_fd('.', 2);
	if (hundredths % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd((int)(hundredths % 100), 2);
	ft_putstr_fd("%\n", 2);
}

void	print_strategy(int mode, double disorder)
{
	int	level;

	ft_putstr_fd("[bench] strategy: ", 2);
	if (mode == 1)
		ft_putstr_fd("Simple / O(n²)", 2);
	else if (mode == 2)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (mode == 3)
		ft_putstr_fd("Complex / O(n log n)", 2);
	else
	{
		ft_putstr_fd("Adaptive / ", 2);
		level = disorder_level(disorder);
		if (level == 0)
			ft_putstr_fd("O(n)", 2);
		else if (level == 1)
			ft_putstr_fd("O(n√n)", 2);
		else
			ft_putstr_fd("O(n log n)", 2);
	}
	ft_putchar_fd('\n', 2);
}