#include "push_swap.h"

int	move_top_b_to_bottom_a(t_stack_holder *sh, int taken_from_b)
{
	pa(sh);
	ra(sh);
	return (taken_from_b + 1);
}

int	move_top_a_to_bottom_a(t_stack_holder *sh, int taken_from_a)
{
	ra(sh);
	return (taken_from_a + 1);
}

void	merge_sort_two(t_stack_holder *sh)
{
	if (sh->a->content > sh->a->next->content)
		sa(sh);
	ra(sh);
	ra(sh);
}
