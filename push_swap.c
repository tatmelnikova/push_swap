#include "push_swap.h"

void test_sa(t_stack_holder	*stack)
{
	// if (c_arg <= 1)
	// {
	// 	print_error();
	// 	return (0);
	// }
	print_stack_holder(stack);
	// sa(stack);
	// print_stack_holder(stack);
	// // pb(stack);
	// // pb(stack);
	// // pb(stack);
	// // pb(stack);
	// // print_stack_holder(stack);
	// // pa(stack);
	// ra(stack);
	// print_stack_holder(stack);
	// rra(stack);
	// print_stack_holder(stack);
	// pb(stack);
	// pb(stack);
	// pb(stack);
	// print_stack_holder(stack);
	// rrb(stack);
	// print_stack_holder(stack);
	// rrb(stack);
	// print_stack_holder(stack);
	// rrr(stack);
	// print_stack_holder(stack);
	bubble_sort(stack); //test
}

int	main(int argc, char *argv[])
{
	t_stack_holder	*stack;

	int args[10]; // 2 1 3 6 5 8
	args[0] = 2;
	args[1] = 1;
	args[2] = 3;
	args[3] = 6;
	args[4] = 5;
	args[5] = 8;
	args[6] = -1;
	args[7] = 10;
	args[8] = 100;
	args[9] = 2;
	printf("args = %d\n", argc);
	if (argc > 1)
	{
		return (get_strategy(argc, argv));
	}
	stack = (t_stack_holder *)malloc(sizeof(t_stack_holder));
	init_stack_holder(stack, args, 10);

	test_sa(stack);
	
	return (0);
}

