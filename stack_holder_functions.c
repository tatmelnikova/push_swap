#include "push_swap.h"

/**
 * @brief Initializes an empty stack holder structure.
 *
 * Sets all pointers to NULL and resets control fields to default values.
 * @param sh Pointer to the stack holder to initialize.
 */
void	init_empty(t_stack_holder *sh)
{
	sh->operations = NULL;
	sh->a = NULL;
	sh->b = NULL;
	sh->disorder = -1;
	sh->strategy = -1;
	sh->chosen_strategy = -1;
}

/**
 * @brief Initializes internal parameters of the stack holder.
 *
 * Prepares stack B, resets counters, clears operations list pointer,
 * and computes the initial disorder of stack A.
 * @param sh Pointer to the stack holder.
 */
static	void	init_params(t_stack_holder *sh)
{
	sh->b = NULL;
	sh->b_count = 0;
	sh->operations = NULL;
	sh->disorder = compute_disorder(sh->a);
}

/**
 * @brief Builds and initializes stack A from input arguments.
 *
 * Creates a linked list from the integer array, assigns it to stack A,
 * sets stack size, and initializes internal parameters.
 * @param sh    Pointer to stack holder.
 * @param args  Array of integers used to build the stack.
 * @return Pointer to initialized stack holder, or NULL on failure.
 */
t_stack_holder	*init_stack_holder(t_stack_holder *sh, int *args)
{
	t_stack		*head;
	t_stack		*new_node;
	int			i;

	i = 0;
	head = NULL;
	while (i < sh->total)
	{
		new_node = st_new(args[i]);
		if (!new_node)
		{
			st_clear(&head);
			return (NULL);
		}
		st_add_back(&head, new_node);
		i++;
	}
	sh->a_count = i;
	sh->a = head;
	init_params(sh);
	return (sh);
}

/**
 * @brief Frees all resources associated with the stack holder.
 *
 * Clears both stacks, operation history, and frees the holder itself.
 * @param sh Pointer to stack holder.
 */
void	clear(t_stack_holder *sh)
{
	if (!sh)
		return ;
	st_clear(&sh->a);
	st_clear(&sh->b);
	op_clear(&sh->operations);
	free(sh);
}

/**
 * @brief Checks if stack A is sorted in ascending order.
 *
 * Iterates through the stack and verifies that each element is
 * less than or equal to the next.
 * @param holder Pointer to stack holder containing stack A.
 * @return 1 if sorted, 0 otherwise.
 */
int	sort_check(t_stack_holder *holder)
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
