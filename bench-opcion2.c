/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rehlich <rehlich@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 21:57:08 by rehlich          #+#    #+#              */
/*   Updated: 2026/11/16 22:41:03 by rehlich         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_ops(t_stack *s, int from, int to)
{
	char	*ops[11] =
	{
		" sa: ", " sb: ", " ss: ", " pa: ", " pb: ",
		" ra: ", " rb: ", " rr: ", " rra: ", " rrb: ", " rrr: "
	};
	ft_putstr_fd("[bench]", 2);
	while (from <= to)
	{
		if (from <= 7)
			ft_putstr_fd(ops[from], 2);
		else
			ft_putstr_fd(ops[from], 2);
		ft_putnbr_fd((int) s->stat_op[from], 2);
		from++;
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
	ft_putnbr_fd((int) s->count_op, 2);
	ft_putchar_fd('\n', 2);
	print_ops(s, 0, 4);
	print_ops(s, 5, 10);
}
