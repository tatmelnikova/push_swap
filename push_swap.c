#include "push_swap.h"

int	main(void)
{
	t_stack_holder	*stack;

	int args[6]; // 2 1 3 6 5 8
	args[0] = 2;
	args[1] = 1;
	args[2] = 3;
	args[3] = 6;
	args[4] = 5;
	args[5] = 8;
	// if (c_arg <= 1)
	// {
	// 	print_error();
	// 	return (0);
	// }
	stack = (t_stack_holder *)malloc(sizeof(t_stack_holder));
	init_stack_holder(stack, args, 6);
	print_stack_holder(stack);
	return (0);
}