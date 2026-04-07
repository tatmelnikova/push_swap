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
	int	strategy;
	int	bench;

	// int args[10]; // 2 1 3 6 5 8
	// args[0] = 2;
	// args[1] = 1;
	// args[2] = 3;
	// args[3] = 6;
	// args[4] = 5;
	// args[5] = 8;
	// args[6] = -1;
	// args[7] = 10;
	// args[8] = 100;
	// args[9] = 2;
	// printf("args = %d\n", argc);
	int	*numbers;
	int	i;
	int size;

	i = 1;
	if (argc > 1)
	{
		strategy = get_strategy(argc, argv);
		bench = get_bench(argc, argv);
		while (i < argc)
		{
			if (is_keyword(argv[i]))
				i++;
			else
				break ;
		}
		if (argc - i > 1)
		{	
			numbers = parse_numbers(&argv[i], argc - i);
			size = argc - i - 1;
		}
		else
		{
			size = count_words(argv[i], ' ');
			char **splited_num = ft_split(argv[i], ' ');
			numbers = parse_numbers(splited_num, size);
		}
		stack = (t_stack_holder *)malloc(sizeof(t_stack_holder));
		init_stack_holder(stack, numbers, size);
		print_stack_holder(stack);
	}
	test_sort(stack);
	return (0);
}
