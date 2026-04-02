#include "push_swap.h"

// Shift up all elements of stack a by one.
// The first element becomes the last one.
void	ra(t_stack_holder *stack_holder)
{
	while (stack_holder->a_count != 0)
	{
		pb(stack_holder);
		ra(stack_holder);
	}
}
// Shift up all elements of stack b by one.
// The first element becomes the last one.
void	rb(t_stack_holder *stack_holder)
{
	while (stack_holder->b_count != 0)
	{
		pa(stack_holder);
		rb(stack_holder);
	}
}