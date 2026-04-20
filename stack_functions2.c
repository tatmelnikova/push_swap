#include "push_swap.h"

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
