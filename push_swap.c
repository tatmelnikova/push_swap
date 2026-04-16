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

	if (argc > 1)
	{
		stack = (t_stack_holder *)malloc(sizeof(t_stack_holder));
		if (!stack)
		{
			print_error();
			exit(0);
		}
		numbers = get_numbers(argc, argv, stack);
		init_stack_holder(stack, numbers);
		stack->strategy = get_strategy(argc, argv);
		stack->bench = get_bench(argc, argv);
		sort(stack);
	}
	else
		print_error();
	return (0);
}
