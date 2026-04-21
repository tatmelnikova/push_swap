/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorenev <skorenev@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:22:55 by skorenev          #+#    #+#             */
/*   Updated: 2026/04/21 19:22:56 by skorenev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates stack A upwards by one position.
 *
 * The first element of stack A becomes the last element.
 * All other elements are shifted up by one position.
 * The operation is recorded as "ra".
 * @param holder Pointer to the stack holder containing stack A.
 */
void	ra(t_stack_holder *holder)
{
	t_stack	*head;
	int		a_count;

	a_count = holder->a_count;
	if (a_count > 1)
	{
		head = holder->a;
		holder->a = head->next;
		head->next = NULL;
		st_add_back(&holder->a, head);
		op_add_back(&holder->operations, op_new("ra"));
	}
}

/**
 * @brief Rotates stack B upwards by one position.
 *
 * The first element of stack B becomes the last element.
 * All other elements are shifted up by one position.
 * The operation is recorded as "rb".
 * @param holder Pointer to the stack holder containing stack B.
 */
void	rb(t_stack_holder *holder)
{
	t_stack	*head;
	int		b_count;

	b_count = holder->b_count;
	if (b_count > 1)
	{
		head = holder->b;
		holder->b = head->next;
		head->next = NULL;
		st_add_back(&holder->b, head);
		op_add_back(&holder->operations, op_new("rb"));
	}
}

/**
 * @brief Rotates both stacks A and B upwards by one position.
 *
 * Executes a simultaneous rotation of stack A and stack B.
 * Equivalent to calling ra() and rb() in sequence.
 * The operation is recorded as "rr".
 * @param stack_holder Pointer to the stack holder containing both stacks.
 */
void	rr(t_stack_holder *holder)
{
	int	a_count;
	int	b_count;

	a_count = holder->a_count;
	b_count = holder->b_count;
	if (a_count > 1 && b_count > 1)
	{
		ra(holder);
		rb(holder);
	}
}
