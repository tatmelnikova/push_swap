#include "push_swap.h"

t_stack_holder *init_stack_holder(t_stack_holder *sh, int *args, int count)
{
	
	t_stack			*head;
	t_stack			*new_node;
	int				i;

	i = 0;
	
	sh->b = NULL;
	head = NULL;
	while (i < count)
	{
		new_node =  st_new(args[i]);
		if (!new_node)
		{
			st_clear(&head);
			return (NULL);
		}
		st_add_back(&head, new_node);
		i++;
	}
	sh->total = i;
	sh->a_count = i;
	sh->b_count = 0;
	sh->a = head;
	return (sh);
}
