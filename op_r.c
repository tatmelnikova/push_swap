#include "push_swap.h"

// Shift up all elements of stack a by one.
// The first element becomes the last one.
void	ra(t_stack_holder *stack_holder)
{
	t_stack	*head;
	int		a_count;

	a_count = stack_holder->a_count;
	assert(a_count);
	if (a_count > 1)
	{
		head = stack_holder->a;
		stack_holder->a = head->next;
		head->next = NULL;
		st_add_back(&stack_holder->a, head);
		op_add_back(&stack_holder->operations, op_new("ra"));
	}
}
// Shift up all elements of stack b by one.
// The first element becomes the last one.
void	rb(t_stack_holder *stack_holder)
{
	t_stack	*head;
	int		b_count;

	b_count = stack_holder->b_count;
	assert(b_count);
	if (b_count > 1)
	{
		head = stack_holder->b;
		stack_holder->b = head->next;
		head->next = NULL;
		st_add_back(&stack_holder->b, head);
		op_add_back(&stack_holder->operations, op_new("rb"));
	}
}

void	rr(t_stack_holder *stack_holder)
{
	int	a_count;
	int	b_count;

	a_count = stack_holder->a_count;
	b_count = stack_holder->b_count;
	assert(a_count);
	assert(b_count);
	if (a_count > 1 && b_count > 1)
	{
		ra(stack_holder);
		rb(stack_holder);
	}
}