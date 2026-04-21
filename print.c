/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorenev <skorenev@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:22:26 by skorenev          #+#    #+#             */
/*   Updated: 2026/04/21 19:22:27 by skorenev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	print_stack_holder(t_stack_holder *holder)
{
	ft_printf(STDOUT_FILENO, "a = ");
	print_stack(holder->a);
	ft_printf(STDOUT_FILENO, "\n");
	ft_printf(STDOUT_FILENO, "b = ");
	print_stack(holder->b);
	ft_printf(STDOUT_FILENO, "\n");
}

/**
 * @brief Prints all recorded operations.
 *
 * Iterates through the operation list and prints each operation
 * in order of execution.
 * @param holder Pointer to the stack holder containing the operations list.
 */
void	print_all_ops(t_stack_holder *holder)
{
	t_operation	*current;

	current = holder->operations;
	while (current)
	{
		ft_printf(STDOUT_FILENO, "%s\n", current->content);
		current = current->next;
	}
}
