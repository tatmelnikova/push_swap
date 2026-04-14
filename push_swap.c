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

void sort(t_stack_holder *stack)
{
	if (stack->strategy == ADAPTIVE)
		stack->chosen_strategy = chose_algorithm(stack->disorder);
	else
		stack->chosen_strategy = stack->strategy;
	if (stack->chosen_strategy == SIMPLE)
		bubble_sort(stack);
	else if (stack->chosen_strategy == MEDIUM)
		bucket_sort(stack);
	else
		merge_sort(stack);
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
	int	j;
	int size;
	int	is_numbers;
	int	is_flags;

	j = 1;
	i = 1;
	is_numbers = 0;
	is_flags = 0;
	if (argc > 1)
	{
		while (argv[j])
		{
			if (is_keyword(argv[j]) && !is_numbers)
			{	
				is_flags = 1;
				i++;
			}
			else if (is_keyword(argv[j]) && is_numbers)
			{
				is_flags = 1;
				is_numbers = -1;
				i++;
			}
			else if (!is_keyword(argv[j]) && is_numbers == -1)
				error();
			else
				is_numbers = 1;
			j++;
		}
		if (argc - i > 1)
		{	
			ft_printf(1, "atoi, i = %d\n", i);
			numbers = parse_numbers(&argv[1], argc - 3);
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
		sort(stack);
	}
	else
		error();
	return (0);
}
