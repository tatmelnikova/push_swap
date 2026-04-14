#include "push_swap.h"

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

// Deletes and frees the given node and all its
// successors. Sets the pointer to the list to NULL.
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

t_operation	*op_last(t_operation *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// Adds the node ’new’ at the end of the list.
// lst: The address of a pointer to the first node of
// a list.
// new: The address of a pointer to the node to be
// added.
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

void print_all_ops(t_stack_holder *st)
{
	t_operation *current;

	current = st->operations;
	while (current)
	{
		ft_printf(STDOUT_FILENO, "%s\n", current->content);
		current = current->next;
	}
}