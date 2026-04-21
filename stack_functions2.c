/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:19:49 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/21 19:19:50 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Returns the last node of a stack.
 *
 * @param lst Pointer to the first node of the stack.
 * @return Pointer to the last node, or NULL if the list is empty.
 */
t_stack	*st_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/**
 * @brief Frees an entire stack.
 *
 * Deletes and frees all nodes in the stack and sets the pointer to NULL.
 * @param lst Double pointer to the head of the stack.
 */
void	st_clear(t_stack **lst)
{
	t_stack	*next_node;

	if (*lst)
	{
		while (*lst)
		{
			next_node = (*lst)->next;
			free(*lst);
			*lst = next_node;
		}
	}
	*lst = NULL;
}

/**
 * @brief Computes the disorder percentage of a stack.
 *
 * Measures how unsorted the stack is by counting inversions:
 * for each pair of elements (i, j), it checks whether a[i] > a[j].
 * The result is expressed as a percentage of total pair comparisons.
 * @param lst Pointer to the stack.
 * @return Disorder percentage in the range [0, 100].
 * 
 * @note A fully sorted stack returns 0.0.
 * @note A fully reversed stack approaches 100.0.
 */
float	compute_disorder(t_stack *lst)
{
	int		mistakes;
	int		pairs;
	t_stack	*current;
	t_stack	*compare_to;

	mistakes = 0;
	pairs = 0;
	current = lst;
	while (current != NULL )
	{
		compare_to = current->next;
		while (compare_to != NULL)
		{
			if (current->content > compare_to->content)
				mistakes++;
			pairs++;
			compare_to = compare_to->next;
		}
		current = current->next;
	}
	if (!pairs)
		return (0.0f);
	return (100.0f * mistakes / pairs);
}
