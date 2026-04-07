#include "push_swap.h"

static void init_params(t_stack_holder *sh)
{
	sh->b = NULL;
	sh->b_count = 0;
	sh->operations = NULL;
	sh->disorder = compute_disorder(sh->a);
	//print_disorder(sh->disorder);
}

t_stack_holder *init_stack_holder(t_stack_holder *sh, int *args, int count)
{
	
	t_stack			*head;
	t_stack			*new_node;
	int				i;

	i = 0;
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
	sh->a = head;
	init_params(sh);
	return (sh);
}

void clear(t_stack_holder *sh)
{
	st_clear(&sh->a);
	st_clear(&sh->b);
	op_clear(&sh->operations);
}
