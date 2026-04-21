/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:18:46 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/21 19:18:47 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Allocates and initializes a new t_operation node with the 
 * given content.
 * 
 * @param content String representing the operation name.
 * @return Pointer to the newly created node, or NULL on allocation failure.
 */
t_operation	*op_new(char *content)
{
	t_operation	*newnode;

	newnode = (t_operation *) malloc(sizeof(t_operation));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

/**
 * @brief Frees all nodes in the list and sets the pointer to NULL.
 * 
 * @param lst Double pointer to the head of the operation list.
 */
void	op_clear(t_operation **lst)
{
	t_operation	*next_node;

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
 * @brief Returns the last node of the operation list.
 *
 * @param lst Pointer to the first node of the list.
 * @return Pointer to the last node, or NULL if the list is empty.
 */
t_operation	*op_last(t_operation *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/**
 * @brief Appends the given node to the end of the list. If the list is empty,
 * the new node becomes the head.
 * 
 * @param lst Pointer to the head pointer of the list.
 * @param new Node to be added at the end.
 */
void	op_add_back(t_operation **lst, t_operation *new)
{
	t_operation	*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = op_last(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

/**
 * @brief Counts operations in a list, optionally filtering by name.
 *
 * Iterates through the list and counts nodes. If a specific operation
 * string is provided, only matching operations are counted.
 * @param lst Pointer to the operation list.
 * @param op  Operation name to filter by, or NULL to count all.
 * @return Number of matching operations.
 */
int	get_op_count(t_operation *lst, char *op)
{
	t_operation	*current;
	int			count;

	current = lst;
	count = 0;
	while (current)
	{
		if (op && !ft_strcmp(current->content, op))
			count++;
		if (!op)
			count++;
		current = current->next;
	}
	return (count);
}
