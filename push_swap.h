/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:13:18 by rehlich           #+#    #+#             */
/*   Updated: 2026/11/18 17:26:42 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
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
	int		size_a;
	int		size_b;
	long	count_op;
	long	stat_op[11];
	int		bench_mode;
	int		strategy;
	double	disorder;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

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
void	sa(t_stack *stack, int silence);
void	sb(t_stack *stack, int silence);
void	ss(t_stack *stack);
void	ra(t_stack *stack, int silent);
void	rb(t_stack *stack, int silent);
void	rr(t_stack *stack);
void	rra(t_stack *stack, int silent);
void	rrb(t_stack *stack, int silent);
void	rrr(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	sort_3(t_stack *stack);
int		find_lowest_index(t_node *node, int index);
void	place_min_to_b(t_stack *stack, int index);
void	sort_5(t_stack *stack);
void	select_strat(t_stack *stack);
void	print_bench(t_stack *stack);
void	print_disorder(double disorder);
void	print_strategy(int mode, double disorder);
int		disorder_level(double disorder);
void	algo_simple(t_stack *stack);
void	algo_medium(t_stack *stack);
void	algo_complex(t_stack *stack);
char	*get_next_line(int fd);
int		is_sorted_bonus(t_stack *stack);
int		run_mov(t_stack *stack, char *line);
int		input_mov(t_stack *stack);
size_t	ft_strlenb(char *str);
char	*ft_strchrb(char *s, int c);
char	*ft_strjoinb(char *s1, char *s2);
char	*ft_substrb(char *s, size_t start, size_t len);
#endif
