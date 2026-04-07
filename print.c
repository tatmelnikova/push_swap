#include "push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void print_stack(t_stack *stack)
{
	t_stack *current_node;
	if (stack)
	{
		current_node = stack;
		while(current_node)
		{
			ft_printf(STDOUT_FILENO, "%d ", current_node->content);
			current_node = current_node->next;
		}
	}
	else
	{
		ft_printf(STDOUT_FILENO, "NULL");
	}
}

void	print_stack_holder(t_stack_holder *sh)
{
	ft_printf(STDOUT_FILENO, "a = ");
	print_stack(sh->a);
	ft_printf(STDOUT_FILENO, "\n");
	// ft_printf("a_count: %d\n", sh->a_count);
	ft_printf(STDOUT_FILENO, "b = ");
	print_stack(sh->b);
	ft_printf(STDOUT_FILENO, "\n");
	// ft_printf("b_count: %d\n", sh->b_count);
}



