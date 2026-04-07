#include "push_swap.h"

void test_sort(t_stack_holder	*stack)
{
	print_stack_holder(stack);
	bubble_sort(stack);
	print_stack_holder(stack);
	print_all_ops(stack);
	if (stack->bench)
		print_bench(stack);
	clear(stack);
}

int	main(int argc, char *argv[])
{
	t_stack_holder	*stack;
	int		*numbers;

	print_args(argc, argv);
	if (argc > 1)
	{
		numbers = parse_numbers(&argv[1], argc - 1);
		stack = (t_stack_holder *)malloc(sizeof(t_stack_holder));
		stack->strategy = get_strategy(argc, argv);
		stack->bench = get_bench(argc, argv);
		init_stack_holder(stack, numbers, argc - 1);
	}
	test_sort(stack);
	return (0);
}
