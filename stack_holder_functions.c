/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_holder_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:20:09 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/21 19:20:11 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Initializes an empty stack holder structure.
 *
 * Sets all pointers to NULL and resets control fields to default values.
 * @param holder Pointer to the stack holder to initialize.
 */
void	init_empty(t_stack_holder *holder)
{
	holder->operations = NULL;
	holder->a = NULL;
	holder->b = NULL;
	holder->disorder = -1;
	holder->strategy = -1;
	holder->chosen_strategy = -1;
}

/**
 * @brief Initializes internal parameters of the stack holder.
 *
 * Prepares stack B, resets counters, clears operations list pointer,
 * and computes the initial disorder of stack A.
 * @param sh Pointer to the stack holder.
 */
static	void	init_params(t_stack_holder *holder)
{
	holder->b = NULL;
	holder->b_count = 0;
	holder->operations = NULL;
	holder->disorder = compute_disorder(holder->a);
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
t_stack_holder	*init_stack_holder(t_stack_holder *holder, int *args)
{
	t_stack		*head;
	t_stack		*new_node;
	int			i;

	i = 0;
	head = NULL;
	while (i < holder->total)
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
	holder->a_count = i;
	holder->a = head;
	init_params(holder);
	return (holder);
}

/**
 * @brief Frees all resources associated with the stack holder.
 *
 * Clears both stacks, operation history, and frees the holder itself.
 * @param holder Pointer to stack holder.
 */
void	clear(t_stack_holder *holder)
{
	if (!holder)
		return ;
	st_clear(&holder->a);
	st_clear(&holder->b);
	op_clear(&holder->operations);
	free(holder);
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
