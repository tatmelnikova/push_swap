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
			printf("%d ", current_node->content);
			current_node = current_node->next;
		}
	}
	else
	{
		printf("NULL");
	}
}

void	print_stack_holder(t_stack_holder *sh)
{
	printf("a = ");
	print_stack(sh->a);
	printf("\n");
	printf("b = ");
	print_stack(sh->b);
	printf("\n");
}

