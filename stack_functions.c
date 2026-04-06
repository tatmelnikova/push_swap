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

t_stack *st_pop_tail(t_stack **stack)
{
	t_stack *prev_node;
	t_stack *current_node;

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

// function compute_disorder(stack a):
// mistakes = 0
// total_pairs = 0
// for i from 0 to size(a)-1:
// for j from i+1 to size(a)-1:
// total_pairs += 1
// if a[i] > a[j]:
// mistakes += 1
// return mistakes / total_pairs

float compute_disorder(t_stack *lst)
{
	int	mistakes;
	int	pairs;
	t_stack *current;
	t_stack *compare_to;

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
	return (100.0f * mistakes / pairs);
}