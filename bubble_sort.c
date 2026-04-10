#include "push_swap.h"


t_stack_holder	*bubble_sort(t_stack_holder *holder)
{
	int	a_count;
	int	i;
	int j;
	t_stack	*first;
	t_stack	*second;

	a_count = holder->a_count;
	j = 0;
	while (j < a_count)
	{
		i = 0;
		if (sort_check(holder))
			break ;
		while (i < a_count - j - 1)
		{
			first = holder->a;
			second = first->next;
			if (first->content > second->content)
				sa(holder);
			pb(holder);
			i++;
		}
		return_in_stack_a(holder);
		j++;
	}
	return(holder);
}
