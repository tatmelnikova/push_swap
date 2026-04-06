#include "push_swap.h"

// pushes the head node from list b to the head of list a
void	pa(t_stack_holder *stack)
{
	t_stack *head_b;

	assert(stack->b_count);
	head_b = st_pop_head(&stack->b);
	st_add_front(&stack->a, head_b);
	stack->a_count = stack->a_count + 1;
	stack->b_count = stack->b_count - 1;
	op_add_back(&stack->operations, op_new("pa"));
}

// pushes the head node from list a to the head of list b
void	pb(t_stack_holder *stack)
{
	t_stack *head_a;

	assert(stack->a_count);
	head_a = st_pop_head(&stack->a);
	st_add_front(&stack->b, head_a);
	stack->a_count = stack->a_count - 1;
	stack->b_count = stack->b_count + 1;
	op_add_back(&stack->operations, op_new("pb"));
}