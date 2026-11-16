#include "push_swap.h"

//Calcula el número máximo de bits (max_bits)
static int	get_max_bits(int size)
{
	int	max_index;
	int	bits;

	if (size <= 1)
		return (0);
	max_index = size - 1;
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}
//Comprueba si la pila A está ordenada
static int	is_sorted(t_stack *stack)
{
	t_node	*curr;

	if (!stack || !stack->top_a)
		return (1);
	curr = stack->top_a;
	while (curr && curr->next)
	{
		if (curr->index > curr->next->index)
			return (0);
		curr = curr->next;
	}
	return (1);
}
//Hace una pasada de ordenación para un bit específico en la pila A.
static void	radix_pass(t_stack *stack, int bit, int size)
{
	int	j;
	int	original_size;

	if (!stack || !stack->top_a || size <= 0)
		return ;
	original_size = size;
	j = 0;
	while (j < original_size)
	{
		if (((stack->top_a->index >> bit) & 1) == 0)
			pb(stack);
		else
			ra(stack, 0);
		j++;
	}
	while (stack->size_b > 0)
		pa(stack);
}
void	algo_complex(t_stack *stack)
{
	int	max_bits;
	int	bit;
	int	size;

	if (!stack || stack->size_a <= 1)
		return ;
	if (is_sorted(stack))
		return ;
	size = stack->size_a;
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		if (is_sorted(stack))
			break ;
		radix_pass(stack, bit, size);
		bit++;
	}
}
