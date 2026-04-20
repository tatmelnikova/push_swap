#include "push_swap.h"

/**
 * @brief Sorts a stack of exactly two elements in ascending order.
 *
 * This function checks the top two elements of stack A and swaps them
 * using `sa` if they are in the wrong order.
 * @param holder Pointer to the stack holder containing stack A.
 * @return t_stack_holder* A pointer to the updated stack holder 
 *         with the two elements sorted.
 */
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

/**
 * @brief eturns the maximum value among three integers.
 * 
 * @param first The first integer to compare.
 * @param second The second integer to compare.
 * @param third The third integer to compare.
 * @return The maximum value among `first`, `second`, and `third`.
 */
int	find_max(int first, int second, int third)
{
	if (first > second && first > third)
		return (first);
	else if (second > first && second > third)
		return (second);
	else
		return (third);
}

/**
 * @brief Sorts a stack of exactly three elements in ascending order.
 *
 * This function sorts the top three elements of stack A using a minimal
 * sequence of stack operations. It first identifies the maximum value
 * among the three elements and moves it to the bottom of the stack using
 * either `ra` or `rra`. Then, it ensures the remaining two elements are
 * in correct order using `sa` if necessary.
 * @param holder Pointer to the stack holder containing stack A.
 * @return t_stack_holder* A pointer to the updated stack holder with 
 *         the three elements sorted.
 */
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
