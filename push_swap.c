#include "push_swap.h"

void test_sort(t_stack_holder	*stack)
{
	print_stack_holder(stack);
	bubble_sort(stack);
	print_stack_holder(stack);
	clear(stack);
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
	// printf("args = %d\n", argc);
	int		*numbers;
	stack = (t_stack_holder *)malloc(sizeof(t_stack_holder));
	if (argc == 2)
	{
		char **splited_num = ft_split(argv[1], ' ');
		numbers = parse_numbers(splited_num, count_words(argv[1], ' '));
		
		init_stack_holder(stack, numbers, count_words(argv[1], ' '));
	}
	else
	{
		init_stack_holder(stack, args, 10);
		stack->strategy = get_strategy(argc, argv);
		stack->bench = get_bench(argc, argv);
		print_args(argc, argv);
	}
	test_sort(stack);
	if (stack->bench)
		print_bench(stack);
	return (0);
}

