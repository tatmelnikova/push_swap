#include "push_swap.h"

static	void	rr_stack(t_stack **stack)
{
	t_stack	*last;

	last = st_pop_tail(stack);
	st_add_front(stack, last);
}

// (reverse rotate b): Shift down all elements of stack b by one.
// The last element becomes the first one.
void	rrb(t_stack_holder *sh)
{
	assert(sh->b_count);
	if (sh->b_count)
	{
		rr_stack(&sh->b);
		op_add_back(&sh->operations, op_new("rrb"));
	}
}

// (reverse rotate a): Shift down all elements of stack a by one.
// The last element becomes the first one.
void	rra(t_stack_holder *sh)
{
	assert(sh->a_count);
	if (sh->a_count)
	{
		rr_stack(&sh->a);
		op_add_back(&sh->operations, op_new("rra"));
	}
}

void	rrr(t_stack_holder *sh)
{
	assert(sh->a_count);
	assert(sh->b_count);
	rra(sh);
	rrb(sh);
}
