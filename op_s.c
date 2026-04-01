#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}
void	sa(t_stack_holder *stack)
{
	if (stack->a_count > 1)
	{
		swap(stack->a);
	}
}

void	sb(t_stack_holder *stack)
{
	if (stack->b_count > 1)
	{
		swap(stack->b);
	}
}
