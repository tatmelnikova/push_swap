#include "push_swap.h"

int chose_algorithm(int disorder)
{
	if (disorder < 20)
		return (SIMPLE);
	if (disorder >= 50)
		return (COMPLEX);
	return (MEDIUM);
}

void sort(t_stack_holder *holder)
{
	if (holder->a_count == 1 || sort_check(holder))
		return ;
	if (holder->strategy == ADAPTIVE)
		holder->chosen_strategy = chose_algorithm(holder->disorder);
	else
		holder->chosen_strategy = holder->strategy;
	if (holder->chosen_strategy == SIMPLE)
		bubble_sort(holder);
	else if (holder->chosen_strategy == MEDIUM)
		bucket_sort(holder);
	else
		merge_sort(holder);
	print_stack_holder(holder);
	print_all_ops(holder);
	if (holder->bench)
		print_bench(holder);
	print_stack_holder(holder);
	clear(holder);
}

int main(int argc, char *argv[])
{
	t_stack_holder *stack;

	int *numbers;
	int i;
	int j;
	int size;
	int is_numbers;
	int is_flags;

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
				print_error();
			else
				is_numbers = 1;
			j++;
		}
		if (argc - i > 1)
		{
			numbers = parse_numbers(&argv[1], argc - i);
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
		// print_stack_holder(stack);
		sort(stack);
	}
	else
		print_error();
	return (0);
}
