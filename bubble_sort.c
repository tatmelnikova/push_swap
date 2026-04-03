#include "push_swap.h"

t_stack_holder	*bubble_sort(t_stack_holder *holder)
{
	t_stack *first;
	t_stack	*second;
	int	a_count;
	int b_count;
	int	i;
	int op_count;

	op_count = 0;
	a_count = holder->a_count;
	while (a_count > 1)
	{
		i = 0;
		while (i <= a_count)
		{
			first = holder->a;
			second = first->next;
			if (first->content < second->content)
			{	
				sa(holder);
				op_count++;
			}
			ra(holder);
			op_count++;
			i++;
		}
		pb(holder);
		a_count = holder->a_count;
	}
	b_count = holder->b_count;
	while (b_count > 0)
	{
		pa(holder);
		op_count++;
		b_count = holder->b_count;
	}
	print_stack_holder(holder);
	ft_printf("op count: %d\n", op_count);
	return (holder);
}
