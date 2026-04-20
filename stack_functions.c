#include "push_swap.h"

// Adds the node ’new’ at the end of the list.
// lst: The address of a pointer to the first node of
// a list.
// new: The address of a pointer to the node to be
// added.
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

// Adds the node ’new’ at the beginning of the list.
// lst: The address of a pointer to the first node of
// a list.
// new: The address of a pointer to the node to be
// added.
void	st_add_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_stack	*st_pop_head(t_stack **stack)
{
	t_stack	*pop_node;

	assert(stack);
	if (!stack || !*stack)
		return (NULL);
	pop_node = *stack;
	*stack = (*stack)->next;
	return (pop_node);
}

t_stack	*st_pop_tail(t_stack **stack)
{
	t_stack	*prev_node;
	t_stack	*current_node;

	assert(stack);
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
