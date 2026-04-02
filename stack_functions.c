#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*newnode;

	newnode = (t_stack *) malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// Deletes and frees the given node and all its
// successors. Sets the pointer to the list to NULL.
void	ft_lstclear(t_stack **lst)
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