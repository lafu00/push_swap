#include "push_swap.h"

void    algo_simple(t_stack *stack)
{
    int     i;
    int     size;

    size = stack->size_a;
    while (i < (size - 3))
    {
        place_min_to_b(stack, i);
        i++;
    }
    sort_3(stack);
    while (stack->size_b > 0)
        pa(stack);
}
