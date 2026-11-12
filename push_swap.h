/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:13:18 by lerodrig          #+#    #+#             */
/*   Updated: 2026/11/12 15:15:59 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top_a;
	t_node	*top_b;
	t_node	*last;
	int		size_a;
	int		size_b;
	long	count_op;
	long	stat_op[11];
	int		bench_mode;
	int		strategy;
	double	disorder;
}	t_stack;

char	**matrix(int argc, char **argv);
void	free_matrix(char **total);
int		extract_flags(char **total);
int		is_valid_number(char **matrix);
long	ft_atol(const char *str, int *error);
int		if_duplicates(int *array, int size);
double	calc_disorder(int *temp, int size);
int		*calc_index(int *temp, int size);
t_stack	*init_stack(t_node *a, int size, int flag, double disorder);
t_node	*fill_stack_a(int *temp, int *indexed, int size);
void	free_nodes(t_node *head);
void	free_all(t_stack *stack);
t_stack	*build_stack(int *values, int *indexes, int size);
void	free_stack(t_stack *s);
void	sa(t_stack *stack, int silence);
void	sb(t_stack *stack, int silence);
void	ss(t_stack *stack);
void	ra(t_stack *stack, int silent);
void	rb(t_stack *stack, int silent);
void	rr(t_stack *stack);
void	rra(t_stack *stack, int silent);
void	rrb(t_stack *stack, int silent);
void	rrr(t_stack *stack);
void	pa(t_stack *stack, int silent);
void	pb(t_stack *stack, int silent);
void	print_stack_debug(t_stack *stack);

#endif
