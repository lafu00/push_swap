/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:13:18 by rehlich           #+#    #+#             */
/*   Updated: 2026/11/10 12:59:10 by rehlich          ###   ########.fr       */
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
t_node	*new_node(int value, int index);
void	add_back(t_stack *s, t_node *n);
t_stack	*build_stack(int *values, int *indexes, int size);
void	free_stack(t_stack *s);
void	print_stack(t_stack *s);
void	sa(t_stack *stack, int silence);
void	sb(t_stack *stack, int silence);
void	ss(t_stack *stack)

#endif
