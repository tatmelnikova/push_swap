#include "push_swap.h"

void	init_empty(t_stack_holder *sh)
{
	sh->operations = NULL;
	sh->a = NULL;
	sh->b = NULL;
}

static	void	init_params(t_stack_holder *sh)
{
	sh->b = NULL;
	sh->b_count = 0;
	sh->operations = NULL;
	sh->disorder = compute_disorder(sh->a);
}

t_stack_holder	*init_stack_holder(t_stack_holder *sh, int *args)
{
	t_stack		*head;
	t_stack		*new_node;
	int			i;

	i = 0;
	head = NULL;
	while (i < sh->total)
	{
		new_node = st_new(args[i]);
		if (!new_node)
		{
			st_clear(&head);
			return (NULL);
		}
		st_add_back(&head, new_node);
		i++;
	}
	assert(sh->total == i);
	sh->a_count = i;
	sh->a = head;
	init_params(sh);
	return (sh);
}

void	clear(t_stack_holder *sh)
{
	if (!sh)
		return ;
	st_clear(&sh->a);
	st_clear(&sh->b);
	op_clear(&sh->operations);
	free(sh);
}

int	sort_check(t_stack_holder *holder)
{
	t_stack	*first;
	t_stack	*second;
	int		is_sorted;

	first = holder->a;
	second = first->next;
	is_sorted = 1;
	while (second->next)
	{
		if (first->content > second->content)
			is_sorted = 0;
		first = second;
		second = second->next;
	}
	if (first->content > second->content)
		is_sorted = 0;
	return (is_sorted);
}
