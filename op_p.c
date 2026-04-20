#include "push_swap.h"

/**
 * @brief Pushes the top element from stack B to stack A.
 *
 * Removes the head node from stack B and places it at the front of stack A.
 * Updates both stack sizes accordingly and records the operation ("pa").
 * @param stack Pointer to the stack holder containing stacks A and B.
 * @note If stack B is empty, behavior depends on st_pop_head() implementation.
 */
void	pa(t_stack_holder *stack)
{
	t_stack	*head_b;

	head_b = st_pop_head(&stack->b);
	st_add_front(&stack->a, head_b);
	stack->a_count = stack->a_count + 1;
	stack->b_count = stack->b_count - 1;
	op_add_back(&stack->operations, op_new("pa"));
}

/**
 * @brief Pushes the top element from stack A to stack B.
 *
 * Removes the head node from stack A and places it at the front of stack B.
 * Updates both stack sizes accordingly and records the operation ("pb").
 * @param stack Pointer to the stack holder containing stacks A and B.
 * @note If stack A is empty, behavior depends on st_pop_head() implementation.
 */
void	pb(t_stack_holder *stack)
{
	t_stack	*head_a;

	head_a = st_pop_head(&stack->a);
	st_add_front(&stack->b, head_a);
	stack->a_count = stack->a_count - 1;
	stack->b_count = stack->b_count + 1;
	op_add_back(&stack->operations, op_new("pb"));
}
