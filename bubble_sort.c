#include "push_swap.h"

/**
 * @brief Moves all elements from stack B back to stack A.
 * 
 * This function repeatedly applies the `pa` operation until stack B
 * is empty, effectively transferring all its elements to stack A.
 * @param holder Pointer to the stack holder structure containing
 *               both stacks and their metadata.
 * @return t_stack_holder* A pointer to the updated stack holder after 
 *         all elements have been moved to stack A.
 */
static t_stack_holder	*return_in_stack_a(t_stack_holder *holder)
{
	while (holder->b_count > 0)
		pa(holder);
	return (holder);
}

/**
 * @brief Sorts stack A using a bubble sort–like algorithm with stack B.
 *
 * This function performs a variation of the bubble sort algorithm using
 * two stacks (A and B) and a limited set of operations:
 *
 * 1. Iteratively traverses stack A, comparing adjacent elements.
 * 2. If the top two elements are out of order, they are swapped using `sa`.
 * 3. Each processed element is pushed to stack B using `pb`, effectively
 *    moving the largest elements toward the end of the sorting process.
 * 4. After each pass, all elements are moved back to stack A using
 *    `return_in_stack_a`.
 * 5. The process repeats until the stack is sorted or all passes are complete.
 * @param holder Pointer to the stack holder containing both stacks
 *               and their associated metadata.
 * @return t_stack_holder* A pointer to the updated stack holder with stack 
 *         A sorted.
 */
t_stack_holder	*bubble_sort(t_stack_holder *holder)
{
	int	a_count;
	int	i;
	int	j;

	a_count = holder->a_count;
	j = 0;
	while (j < a_count)
	{
		i = 0;
		if (sort_check(holder))
			break ;
		while (i < a_count - j - 1)
		{
			if (holder->a->content > holder->a->next->content)
				sa(holder);
			pb(holder);
			i++;
		}
		return_in_stack_a(holder);
		j++;
	}
	return (holder);
}
