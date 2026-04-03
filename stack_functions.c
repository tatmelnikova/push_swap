#include "push_swap.h"

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
t_stack *st_pop_head(t_stack **stack)
{
	t_stack *pop_node;

	assert(stack);
	if (!stack || !*stack)
		return (NULL);

	pop_node = *stack;
	*stack = (*stack)->next;
	return (pop_node);
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

t_stack	*st_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// Deletes and frees the given node and all its
// successors. Sets the pointer to the list to NULL.
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