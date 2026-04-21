#include "push_swap.h"

/**
 * @brief Assigns a rank to each element in stack A based on its value.
 *
 * This function iterates through all elements in stack A and computes
 * a relative rank (`range`) for each node. The rank corresponds to the
 * number of elements in the stack that have a smaller value than the
 * current node.
 * @param holder Pointer to the stack holder containing stack A.
 */
void	find_rang(t_stack_holder *holder)
{
	int		range;
	t_stack	*node;
	t_stack	*compare_node;

	node = holder->a;
	while (node)
	{
		range = 0;
		compare_node = holder->a;
		while (compare_node)
		{
			if (node->content > compare_node->content)
				range++;
			compare_node = compare_node->next;
		}
		node->range = range;
		node = node->next;
	}
}

int	edge_casees_sort_check(t_stack_holder *holder)
{
	if (holder->a_count == 2)
	{
		sort_two(holder);
		return (1);
	}
	else if (holder->a_count == 3)
	{
		sort_three(holder);
		return (1);
	}
	else if (holder->a_count == 5)
	{
		sort_five(holder);
		return (1);
	}
	return (0);
}
