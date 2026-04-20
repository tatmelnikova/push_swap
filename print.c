#include "push_swap.h"

/**
 * @brief Outputs "Error\n" to standard output.
 */
void	print_error(void)
{
	write(STDOUT_FILENO, "Error\n", 6);
}

/**
 * @brief Prints the contents of a stack.
 *
 * Iterates through the linked list and prints each node's content.
 * If the stack is empty, prints "NULL".
 * @param stack Pointer to the first node of the stack.
 */
void	print_stack(t_stack *stack)
{
	t_stack	*current_node;

	if (stack)
	{
		current_node = stack;
		while (current_node)
		{
			ft_printf(STDOUT_FILENO, "%d ", current_node->content);
			current_node = current_node->next;
		}
	}
	else
	{
		ft_printf(STDOUT_FILENO, "NULL");
	}
}

/**
 * @brief Prints both stacks inside a stack holder.
 * 
 * Displays stack A and stack B with labels for debugging purposes.
 * @param sh Pointer to the stack holder containing stacks A and B.
 */
void	print_stack_holder(t_stack_holder *sh)
{
	ft_printf(STDOUT_FILENO, "a = ");
	print_stack(sh->a);
	ft_printf(STDOUT_FILENO, "\n");
	// ft_printf("a_count: %d\n", sh->a_count);
	ft_printf(STDOUT_FILENO, "b = ");
	print_stack(sh->b);
	ft_printf(STDOUT_FILENO, "\n");
	// ft_printf("b_count: %d\n", sh->b_count);
}

/**
 * @brief Prints all recorded operations.
 *
 * Iterates through the operation list and prints each operation
 * in order of execution.
 * @param st Pointer to the stack holder containing the operations list.
 */
void	print_all_ops(t_stack_holder *st)
{
	t_operation	*current;

	current = st->operations;
	while (current)
	{
		ft_printf(STDOUT_FILENO, "%s\n", current->content);
		current = current->next;
	}
}
