/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:19:13 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/21 19:19:14 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Computes the number of bits required for the largest index.
 *
 * Finds the maximum `range` value in the stack and calculates how many
 * bits are needed to represent it in binary.
 * @param a Pointer to the stack.
 * @return Number of bits required for the largest value.
 */
int	get_max_bits(t_stack *a)
{
	int	max;
	int	max_bits;

	max = INT_MIN;
	max_bits = 0;
	while (a)
	{
		if (a->range > max)
			max = a->range;
		a = a->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/**
 * @brief Initializes all node ranges to -1.
 *
 * Sets the `range` field of every node in stack A to -1,
 * preparing the stack for indexing.
 * @param stack Pointer to the stack holder.
 */
void	init_ranges(t_stack_holder *holder)
{
	t_stack	*current;

	current = holder->a;
	while (current)
	{
		current->range = -1;
		current = current->next;
	}
}

/**
 * @brief Assigns sorted index ranges to stack elements.
 *
 * Replaces each node's value with a normalized index (rank) based
 * on ascending order of `content`. This is used for radix sorting.
 * @param holder Pointer to the stack holder containing stack A.
 */
void	apply_ranges(t_stack_holder *holder)
{
	int		i;
	int		min_val;
	t_stack	*min_node;
	t_stack	*current;

	i = 0;
	while (i < holder->total)
	{
		min_val = INT_MAX;
		current = holder->a;
		while (current)
		{
			if (current->content <= min_val && current->range == -1)
			{
				min_val = current->content;
				min_node = current;
			}
			current = current->next;
		}
		min_node->range = i;
		i++;
	}
}

/**
 * @brief Performs radix sort on stack A using stack B as auxiliary storage.
 *
 * Implements binary radix sort using the `range` field of nodes.
 * Elements are distributed between stacks A and B based on bit values,
 * then reassembled over multiple passes.
 * @param holder Pointer to the stack holder containing both stacks.
 */
void	execute_sort(t_stack_holder *holder)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	size = holder->a_count;
	i = 0;
	max_bits = get_max_bits(holder->a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((holder->a->range >> i) & 1) == 0)
				pb(holder);
			else
				ra(holder);
			j++;
		}
		while (holder->b_count > 0)
			pa(holder);
		i++;
	}
}

/**
 * @brief Prepares necessary range calculation and runs the sort function
 *
 * @param holder Pointer to the stack holder containing both stacks.
 */
void	radix_sort(t_stack_holder *holder)
{
	if (edge_casees_sort_check(holder))
		return ;
	init_ranges(holder);
	apply_ranges(holder);
	execute_sort(holder);
}
