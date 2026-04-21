/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorenev <skorenev@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:21:51 by skorenev          #+#    #+#             */
/*   Updated: 2026/04/21 19:21:52 by skorenev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first two elements of a stack.
 *
 * Exchanges the content values of the first two nodes in the stack.
 * This does not change node links, only their stored values.
 * @param stack Pointer to the stack whose top two elements are swapped.
 */
static void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

/**
 * @brief Swaps the first two elements of stack A.
 *
 * Performs a swap of the top two elements of stack A.
 * The operation is recorded as "sa".
 * @param holder Pointer to the stack holder containing stack A.
 */
void	sa(t_stack_holder *holder)
{
	int	a_count;

	a_count = holder->a_count;
	if (a_count > 1)
	{
		swap(holder->a);
		op_add_back(&holder->operations, op_new("sa"));
	}
}

/**
 * @brief Swaps the first two elements of stack B.
 *
 * Performs a swap of the top two elements of stack B.
 * The operation is recorded as "sb".
 * @param holder Pointer to the stack holder containing stack B.
 */
void	sb(t_stack_holder *holder)
{
	if (holder->b_count > 1)
	{
		swap(holder->b);
		op_add_back(&holder->operations, op_new("sb"));
	}
}

/**
 * @brief Swaps the first two elements of both stacks A and B.
 *
 * Applies the swap operation to both stacks:
 * - stack A via sa()
 * - stack B via sb()
 * The operation is conceptually recorded as "ss".
 * @param holder Pointer to the stack holder containing both stacks.
 */
void	ss(t_stack_holder *holder)
{
	int	a_count;
	int	b_count;

	a_count = holder->a_count;
	b_count = holder->b_count;
	if (a_count > 1 && b_count > 1)
	{
		sa(holder);
		sb(holder);
	}
}
