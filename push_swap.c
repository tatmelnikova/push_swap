#include "push_swap.h"

int chose_algorithm(int disorder)
{
	if (disorder < 20)
		return (SIMPLE);
	if (disorder >= 50)
		return (COMPLEX);
	return (MEDIUM);
}

// clear stack holder and exit program.
// @throw_error if != 0, print error message before exit
static int	clear_and_exit(t_stack_holder *sh, int throw_error)
{
	if (throw_error)
		print_error();
	clear(sh);
	return (0);
}

void sort(t_stack_holder *holder)
{
	if (holder->a_count == 1 || sort_check(holder))
		return ;
	if (holder->strategy == ADAPTIVE)
		holder->chosen_strategy = chose_algorithm(holder->disorder);
	else
		holder->chosen_strategy = holder->strategy;
	if (holder->a_count == 2)
		sort_two(holder);
	else if (holder->a_count == 3)
		sort_three(holder);
	else if (holder->chosen_strategy == SIMPLE)
		bubble_sort(holder);
	else if (holder->chosen_strategy == MEDIUM)
		bucket_sort(holder);
	else
		merge_sort(holder);
	print_all_ops(holder);
	if (holder->bench)
		print_bench(holder);
	if (holder->debug)
		print_stack_holder(holder);
}

int main(int argc, char *argv[])
{
	t_stack_holder *stack;
	int *numbers;

	stack = (t_stack_holder *)malloc(sizeof(t_stack_holder));
	if (!stack)
		return (clear_and_exit(stack, 1));
	if (argc > 1)
	{
		numbers = get_numbers(argc, argv, stack);
		if (!numbers)
		{
			free(stack);
			return (clear_and_exit(NULL, 1));
		}
		init_stack_holder(stack, numbers);
		free(numbers);
		stack->strategy = get_strategy(argc, argv);
		stack->bench = get_bench(argc, argv);
		stack->debug = get_debug(argc, argv);
		sort(stack);
	}
	else
		return (clear_and_exit(stack, 1));
	return (clear_and_exit(stack, 0));
}
