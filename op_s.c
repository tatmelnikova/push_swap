#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	sa(t_stack_holder *stack_holder)
{
	int	a_count;

	a_count = stack_holder->a_count;
	assert(a_count);
	if (a_count > 1)
	{
		swap(stack_holder->a);
		op_add_back(&stack_holder->operations, op_new("sa"));
	}
	ft_printf("sa\n");
}

void	sb(t_stack_holder *stack_holder)
{
	int	b_count;

	b_count = stack_holder->b_count;
	assert(b_count);
	if (stack_holder->b_count > 1)
	{
		swap(stack_holder->b);
		op_add_back(&stack_holder->operations, op_new("sb"));
	}
	ft_printf("sb\n");
}

void	ss(t_stack_holder *stack_holder)
{
	int	a_count;
	int	b_count;

	a_count = stack_holder->a_count;
	b_count = stack_holder->b_count;
	assert(a_count);
	assert(b_count);

	if (a_count > 1 && b_count > 1)
	{
		sa(stack_holder);
		sb(stack_holder);
	}
}