#include "push_swap.h"

/**
 * @brief Computes the number of bits required for the largest index.
 *
 * Finds the maximum `range` value in the stack and calculates how many
 * bits are needed to represent it in binary.
 * @param a Pointer to the stack.
 * @return Number of bits required for the largest value.
 */
int	get_max_bits(t_stack *a)
{
	int	max;
	int	max_bits;

	max = INT_MIN;
	max_bits = 0;
	while (a)
	{
		if (a->range > max)
			max = a->range;
		a = a->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/**
 * @brief Initializes all node ranges to -1.
 *
 * Sets the `range` field of every node in stack A to -1,
 * preparing the stack for indexing.
 * @param stack Pointer to the stack holder.
 */
void	init_ranges(t_stack_holder *stack)
{
	t_stack	*current;

	current = stack->a;
	while (current)
	{
		current->range = -1;
		current = current->next;
	}
}

/**
 * @brief Assigns sorted index ranges to stack elements.
 *
 * Replaces each node's value with a normalized index (rank) based
 * on ascending order of `content`. This is used for radix sorting.
 * @param stack Pointer to the stack holder containing stack A.
 */
void	apply_ranges(t_stack_holder *stack)
{
	int		i;
	int		min_val;
	t_stack	*min_node;
	t_stack	*current;

	i = 0;
	while (i < stack->total)
	{
		min_val = INT_MAX;
		current = stack->a;
		while (current)
		{
			if (current->content <= min_val && current->range == -1)
			{
				min_val = current->content;
				min_node = current;
			}
			current = current->next;
		}
		min_node->range = i;
		i++;
	}
}

/**
 * @brief Performs radix sort on stack A using stack B as a temporary storage.
 *
 * Implements binary radix sort using the `range` field of nodes.
 * Elements are distributed between stacks A and B based on bit values,
 * then reassembled over multiple passes.
 * @param sh Pointer to the stack holder containing both stacks.
 */
void	radix_sort(t_stack_holder *sh)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = sh->a_count;
	init_ranges(sh);
	apply_ranges(sh);
	max_bits = get_max_bits(sh->a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((sh->a->range >> i) & 1) == 0)
				pb(sh);
			else
				ra(sh);
			j++;
		}
		while (sh->b_count > 0)
			pa(sh);
		i++;
	}
}
