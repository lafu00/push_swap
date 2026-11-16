#include "push_swap.h"

static  int ft_sqrt(int size)
{
	int	aux;

	aux = 0;
	while (aux * aux <= size)
	{
		if (aux * aux == size)
			return (aux);
		aux++;
	}
	return (0);
}

static void     fill_b(t_stack *stack, int range)
{
    int i;

    i = 0;
    while (stack->size_a > 0)
    {
        if (stack->top_a->index <= i)
        {
            pb(stack);
            rb(stack, 0);
            i++;
        }
        else if (stack->top_a->index <= i + range)
        {
            pb(stack);
            i++;
        }
        else if (i + range)
            ra(stack, 0);
    }
}

void    algo_medium(t_stack *stack)
{
    int range;
    int j;
    int pos;

    range = ft_sqrt((stack->size_a) * 3) / 2;
    j = stack->size_b - 1;
    while (stack->size_b > 0)
    {
        pos = find_lowest_index(stack->top_a, j);
        if (pos <= stack->size_b / 2)
            ra(stack, 0);
        else
            rra(stack, 0);
        pa(stack);
    } 
}
