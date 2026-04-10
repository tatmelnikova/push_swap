#include "push_swap.h"

int	chose_algorithm(int disorder)
{
	if (disorder < 20)
		return (SIMPLE);
	if (disorder >= 50)
		return (COMPLEX);
	else
		return (MEDIUM);
}

void test_sort(t_stack_holder	*stack)
{
	int	strategy;
	if (stack->strategy == ADAPTIVE)
		strategy = chose_algorithm(stack->disorder);
	else
		strategy = stack->strategy;
	if (strategy == SIMPLE)
	{	
		bubble_sort(stack);
		ft_printf(1, "SIMPLE\n");
	}
	else if (strategy == MEDIUM)
	{	
		bucket_sort(stack);
		ft_printf(1, "MEDIUM\n");
	}
	else
	{	
		merge_sort(stack);
		ft_printf(1, "COMPLEX\n");
	}
	print_stack_holder(stack);
	print_all_ops(stack);
	if (stack->bench)
		print_bench(stack);
	print_stack_holder(stack);
	clear(stack);
}

int	main(int argc, char *argv[])
{
	t_stack_holder	*stack;

	int	*numbers;
	int	i;
	int size;

	i = 1;
	if (argc > 1)
	{
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
			size = argc - i;
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
	}
	else
		error();
	return (0);
}
