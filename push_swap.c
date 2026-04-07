#include "push_swap.h"

void test_sort(t_stack_holder	*stack)
{
	// print_stack_holder(stack);
	bubble_sort(stack);
	// print_stack_holder(stack);
	print_all_ops(stack);
	if (stack->bench)
		print_bench(stack);
	clear(stack);
}

int	main(int argc, char *argv[])
{
	t_stack_holder	*stack;

	int	*numbers;
	int	i;
	int size;

	i = 1;
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
		stack->strategy = get_strategy(argc, argv);
		stack->bench = get_bench(argc, argv);
		//print_stack_holder(stack);
	test_sort(stack);
	return (0);
}
