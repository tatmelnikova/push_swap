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
	int keywords_count;
	int size;

	keywords_count = 1;
	if (argc > 1)
	{
		keywords_count = count_keywords(argc, argv);
		if (argc - keywords_count > 1)
		{
			numbers = parse_numbers(&argv[1], argc - keywords_count);
			size = argc - keywords_count;
		}
		else
		{
			size = count_words(argv[keywords_count], ' ');
			char **splited_num = ft_split(argv[keywords_count], ' ');
			numbers = parse_numbers(splited_num, size);
		}
		stack = (t_stack_holder *)malloc(sizeof(t_stack_holder));
		init_stack_holder(stack, numbers, size);
		stack->strategy = get_strategy(argc, argv);
		stack->bench = get_bench(argc, argv);
		sort(stack);
	}
	else
		print_error();
	return (0);
}
