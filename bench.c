/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 21:57:08 by lerodrig          #+#    #+#             */
/*   Updated: 2026/11/15 21:57:41 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*op_name(int i)
{
	if (i == 0)
		return ("sa");
	if (i == 1)
		return ("sb");
	if (i == 2)
		return ("ss");
	if (i == 3)
		return ("pa");
	if (i == 4)
		return ("pb");
	if (i == 5)
		return ("ra");
	if (i == 6)
		return ("rb");
	if (i == 7)
		return ("rr");
	if (i == 8)
		return ("rra");
	if (i == 9)
		return ("rrb");
	return ("rrr");
}

static void	print_ops(t_stack *s, int from, int to)
{
	int	i;

	ft_putstr_fd("[bench]", 2);
	i = from;
	while (i <= to)
	{
		ft_putchar_fd(' ', 2);
		ft_putstr_fd(op_name(i), 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd((int)s->stat_op[i], 2);
		i++;
	}
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_stack *s)
{
	if (!s->bench_mode)
		return ;
	print_disorder(s->disorder);
	print_strategy(s->strategy, s->disorder);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd((int)s->count_op, 2);
	ft_putchar_fd('\n', 2);
	print_ops(s, 0, 4);
	print_ops(s, 5, 10);
}