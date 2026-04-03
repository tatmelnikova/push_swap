#include "push_swap.h"

static t_stack_holder	*return_in_stack_a(t_stack_holder *holder)
{
	while (holder->b_count > 0)
		pa(holder);
	return (holder);
}

static int	sort_check(t_stack_holder *holder)
{
	t_stack	*first;
	t_stack	*second;
	int		is_sorted;

	first = holder->a;
	second = first->next;
	is_sorted = 1;
	while (second->next)
	{
		if (first->content > second->content)
			is_sorted = 0;
		first = second;
		second = second->next;
	}
	if (first->content > second->content)
		is_sorted = 0;
	return (is_sorted);
}

t_stack_holder	*bubble_sort(t_stack_holder *holder)
{
	t_stack	*first;
	t_stack	*second;
	int		i;
	
	while (holder->a_count > 1)
	{
		i = 0;
		
		while (i <= holder->a_count)
		{
			first = holder->a;
			second = first->next;
			if (first->content < second->content)

				sa(holder);
			ra(holder);
			i++;
		}
		if (sort_check(holder))
			break ;
		pb(holder);
	}
	return_in_stack_a(holder);
	print_stack_holder(holder);
	return (holder);
}
