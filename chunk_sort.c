#include "push_swap.h"

/**
 * @brief Computes the integer square root of a number.
 *
 * This function calculates the integer square root of a given number `nb`
 * using a binary search algorithm. The result is the largest integer `x`
 * such that x * x ≤ nb.
 * @param nb The number for which to compute the square root.
 * @return int The integer square root of `nb`. Returns 0 if `nb` is negative.
 */
static	int	ft_sqrt(int nb)
{
	int				middle;
	int				left;
	int				right;
	unsigned long	sqrt;
	unsigned long	nb_long;

	left = 0;
	right = nb;
	nb_long = nb;
	if (nb < 0)
		return (0);
	while (left <= right)
	{
		middle = (right + left) / 2;
		sqrt = middle * middle;
		if (sqrt == nb_long)
			return (middle);
		else if (sqrt > nb_long)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return (right);
}

/**
 * @brief Finds the index of the node with the highest rank in stack B.
 *
 * This function iterates through stack B to locate the element with the
 * maximum `range` value and returns its position (0-based index).
 * @param holder Pointer to the stack holder containing stack B.
 * @return int The index of the node with the highest `range` in stack B.
 */
static int	find_max_place(t_stack_holder *holder)
{
	int		i;
	int		max;
	int		index;
	t_stack	*node;

	i = 0;
	index = 0;
	max = holder->b->range;
	node = holder->b;
	while (node)
	{
		if (node->range > max)
		{
			index = i;
			max = node->range;
		}
		i++;
		node = node->next;
	}
	return (index);
}

/**
 * @brief Moves all elements from stack B to stack A in descending order.
 *
 * This function transfers elements from stack B back to stack A by always
 * selecting the element with the highest `range` value (i.e., the largest).
 * It minimizes the number of operations by choosing the shortest rotation
 * path:
 *   - Uses `rb` (rotate) if the target element is in the first half
 *   - Uses `rrb` (reverse rotate) if it is in the second half
 * Once the target element is at the top of stack B, it is pushed to
 * stack A using `pa`.
 * @param holder Pointer to the stack holder containing both stacks
 *               and their associated metadata.
 * @return t_stack_holder* A pointer to the updated stack holder after 
 *         all elements have been moved to stack A.
 */
static t_stack_holder	*return_in_stack_a(t_stack_holder *holder)
{
	int	max_index;
	int	i;

	while (holder->b_count)
	{
		max_index = find_max_place(holder);
		if (max_index <= holder->b_count / 2)
		{
			i = max_index;
			while (i-- > 0)
				rb(holder);
		}
		else
		{
			i = holder->b_count - max_index;
			while (i-- > 0)
				rrb(holder);
		}
		pa(holder);
	}
	return (holder);
}

// moves next node to stack B if it doesn't belong to current range,
// otherwise pushes the node to the bottom of stack A
int	move_next_node(int range, int sqrt_n, t_stack_holder *holder)
{
	t_stack	*node;
	node = holder->a;
	if (node->range >= range && node->range < range + sqrt_n)
	{
		pb(holder);
		return (-1);
	}
	else
		ra(holder);
	return (0);
}

/**
 * @brief Sorts stack A using a chunk-based algorithm and auxiliary stack B.
 *  Overall complexity is approximately O(n√n)
 *
 * This function implements a chunking strategy to sort elements in stack A:
 *
 * 1. Each element is first assigned a `range` (rank) using `find_rang`,
 *    representing its relative order.
 * 2. The stack is divided into chunks of size √n (where n = number of elements).
 * 3. Elements are pushed (`pb`) from stack A to stack B if their rank falls
 *    within the current chunk range [range, range + √n).
 *    Otherwise, stack A is rotated (`ra`) to bring new candidates to the top.
 * 4. The chunk range is incremented progressively until all elements are moved
 *    to stack B.
 * 5. Finally, elements are moved back to stack A in sorted order using
 *    `return_in_stack_a`, which places the largest elements first.
 * @param holder Pointer to the stack holder containing both stacks
 *               and their associated metadata.
 * @return t_stack_holder* A pointer to the updated stack holder with 
 *         stack A sorted.
 */
t_stack_holder	*chunk_sort(t_stack_holder *holder)
{
	int		j;
	int		range;
	int		sqrt_n;

	if (edge_casees_sort_check(holder))
		return (holder);
	range = 0;
	sqrt_n = ft_sqrt(holder->a_count);
	find_rang(holder);
	while (holder->a_count)
	{
		j = sqrt_n;
		while (holder->a_count != 0 && j > 0)
			j += move_next_node(range, sqrt_n, holder);
		range += sqrt_n;
	}
	return (return_in_stack_a(holder));
}
