/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:17:54 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/21 19:17:55 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the top element from stack B to stack A.
 *
 * Removes the head node from stack B and places it at the front of stack A.
 * Updates both stack sizes accordingly and records the operation ("pa").
 * @param holder Pointer to the stack holder containing stacks A and B.
 * @note If stack B is empty, behavior depends on st_pop_head() implementation.
 */
void	pa(t_stack_holder *holder)
{
	t_stack	*head_b;

	head_b = st_pop_head(&holder->b);
	st_add_front(&holder->a, head_b);
	holder->a_count = holder->a_count + 1;
	holder->b_count = holder->b_count - 1;
	op_add_back(&holder->operations, op_new("pa"));
}

/**
 * @brief Pushes the top element from stack A to stack B.
 *
 * Removes the head node from stack A and places it at the front of stack B.
 * Updates both stack sizes accordingly and records the operation ("pb").
 * @param stack Pointer to the stack holder containing stacks A and B.
 * @note If stack A is empty, behavior depends on st_pop_head() implementation.
 */
void	pb(t_stack_holder *holder)
{
	t_stack	*head_a;

	head_a = st_pop_head(&holder->a);
	st_add_front(&holder->b, head_a);
	holder->a_count = holder->a_count - 1;
	holder->b_count = holder->b_count + 1;
	op_add_back(&holder->operations, op_new("pb"));
}
