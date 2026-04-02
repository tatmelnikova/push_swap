#include "push_swap.h"

void	pa(t_stack_holder *stack)
{
	assert(stack->b_count);
}

// pushes the head node from list a to the head of list b
void	pb(t_stack_holder *stack)
{
	t_stack *head_a;

	assert(stack->a_count);
	head_a = pop_head(&stack->a);
	ft_lstadd_front(&stack->b, head_a);
}