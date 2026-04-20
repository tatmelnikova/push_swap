#include "push_swap.h"

t_stack_holder	*sort_two(t_stack_holder *holder)
{
	t_stack	*first;
	t_stack	*second;

	first = holder->a;
	second = first->next;
	if (first->content > second->content)
		sa(holder);
	return (holder);
}

int	find_max(int first, int second, int third)
{
	if (first > second && first > third)
		return (first);
	else if (second > first && second > third)
		return (second);
	else
		return (third);
}

t_stack_holder	*sort_three(t_stack_holder *holder)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	int		max;

	first = holder->a;
	second = first->next;
	third = second->next;
	max = find_max(first->content, second->content, third->content);
	if (first->content == max)
		ra(holder);
	else if (second->content == max)
		rra(holder);
	first = holder->a;
	second = first->next;
	if (first->content > second->content)
		sa(holder);
	return (holder);
}
