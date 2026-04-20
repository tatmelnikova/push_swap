#include "push_swap.h"

/**
 * @brief Adds the node `new` to the end of the linked list. 
 * If the list is empty, the new node becomes the head.
 * 
 * @param lst Pointer to the head pointer of the stack.
 * @param new Node to be appended.
 */
void	st_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = st_last(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

/**
 * @brief Places the node `new` at the front of the list, making it 
 * the new head.
 * 
 * @param lst Pointer to the head pointer of the stack.
 * @param new Node to be inserted.
 */
void	st_add_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/**
 * @brief Removes and returns the head node of a stack.
 *
 * Detaches the first node from the stack and returns it.
 * The stack head is updated accordingly.
 * @param stack Pointer to the head pointer of the stack.
 * @return Pointer to the removed head node, or NULL if empty.
 */
t_stack	*st_pop_head(t_stack **stack)
{
	t_stack	*pop_node;

	if (!stack || !*stack)
		return (NULL);
	pop_node = *stack;
	*stack = (*stack)->next;
	return (pop_node);
}

/**
 * @brief Removes and returns the last node of a stack.
 *
 * @param stack Pointer to the head pointer of the stack.
 * @return Pointer to the removed last node, or NULL if empty.
 */
t_stack	*st_pop_tail(t_stack **stack)
{
	t_stack	*prev_node;
	t_stack	*current_node;

	if (!stack || !*stack)
		return (NULL);
	current_node = *stack;
	prev_node = NULL;
	while (current_node->next)
	{
		prev_node = current_node;
		current_node = current_node->next;
	}
	prev_node->next = NULL;
	return (current_node);
}

/**
 * @brief Creates a new stack node.
 *
 * Allocates and initializes a new node with the given content.
 * @param content Integer value to store in the node.
 * @return Pointer to the newly created node, or NULL on failure.
 */
t_stack	*st_new(int content)
{
	t_stack	*newnode;

	newnode = (t_stack *) malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
