#include "push_swap.h"

/**
 * @brief Performs a reverse rotation on a stack.
 *
 * Moves the last element of the stack to the front, effectively shifting
 * all elements down by one position.
 * This is an internal helper function used by rra and rrb.
 * @param stack Pointer to the stack to be rotated.
 */
static	void	rr_stack(t_stack **stack)
{
	t_stack	*last;

	last = st_pop_tail(stack);
	st_add_front(stack, last);
}

/**
 * @brief Reverse rotates stack B.
 *
 * The last element of stack B becomes the first element.
 * All other elements are shifted down by one position.
 * The operation is recorded as "rrb".
 * @param sh Pointer to the stack holder containing stack B.
 */
void	rrb(t_stack_holder *sh)
{
	if (sh->b_count)
	{
		rr_stack(&sh->b);
		op_add_back(&sh->operations, op_new("rrb"));
	}
}

/**
 * @brief Reverse rotates stack A.
 *
 * The last element of stack A becomes the first element.
 * All other elements are shifted down by one position.
 * The operation is recorded as "rra".
 * @param sh Pointer to the stack holder containing stack A.
 */
void	rra(t_stack_holder *sh)
{
	if (sh->a_count)
	{
		rr_stack(&sh->a);
		op_add_back(&sh->operations, op_new("rra"));
	}
}

/**
 * @brief Reverse rotates both stacks A and B.
 *
 * Applies reverse rotation to both stacks:
 * - stack A via rra()
 * - stack B via rrb()
 * The operation is conceptually recorded as "rrr".
 * @param sh Pointer to the stack holder containing both stacks.
 */
void	rrr(t_stack_holder *sh)
{
	rra(sh);
	rrb(sh);
}
