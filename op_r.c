#include "push_swap.h"

// Shift up all elements of stack a by one.
// The first element becomes the last one.
void	ra(t_stack_holder *stack_holder)
{
	t_stack	*head;

	if (stack_holder->a_count > 1)
	{
		head = stack_holder->a;
		stack_holder->a = head->next;
		head->next = NULL;
		st_add_back(&stack_holder->a, head);
	}
}
// Shift up all elements of stack b by one.
// The first element becomes the last one.
void	rb(t_stack_holder *stack_holder)
{
	t_stack	*head;

	if (stack_holder->b_count > 1)
	{
		head = stack_holder->b;
		stack_holder->b = head->next;
		head->next = NULL;
		st_add_back(&stack_holder->b, head);
	}
}