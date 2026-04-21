#include "push_swap.h"

/**
 * @brief Frees all allocated resources and exits the program.
 *
 * Clears the stack holder and optionally prints an error message
 * before exiting.
 * @param sh          Pointer to stack holder to be cleared.
 * @param throw_error If non-zero, prints an error message before exit.
 * @return Always returns 0.
 */
static int	clear_and_exit(t_stack_holder *sh, int throw_error)
{
	if (throw_error)
		print_error();
	clear(sh);
	return (0);
}

void sort_adaptive(t_stack_holder *holder)
{
	if (holder->a_count == 2)
		sort_two(holder);
	else if (holder->a_count == 3)
		sort_three(holder);
	else if (holder->disorder < 20)
		bubble_sort(holder);
	else if (holder->disorder < 50)
		chunk_sort(holder);
	else
		radix_sort(holder);
}

/**
 * @brief Executes sorting logic on the stack holder.
 *
 * Selects the appropriate sorting strategy based on disorder level, 
 * and given flags. Executes the sorting algorithm
 * and optionally prints benchmark information.
 * @param holder Pointer to stack holder containing all sorting data.
 */
void	sort(t_stack_holder *holder)
{
	if (holder->a_count == 1 || sort_check(holder))
		return ;
	if (holder->strategy == SIMPLE)
		bubble_sort(holder);
	else if (holder->strategy == MEDIUM)
		chunk_sort(holder);
	else if (holder->strategy == COMPLEX)
		radix_sort(holder);
	else
		sort_adaptive(holder);
	print_all_ops(holder);
	if (holder->bench)
		print_bench(holder);
	//print_stack_holder(holder);
}

/**
 * @brief Program entry point for push_swap.
 *
 * Parses input arguments, initializes the stack holder, selects the
 * strategy and benchmark mode, executes sorting, and performs cleanup
 * before exit.
 * @param argc Number of command-line arguments.
 * @param argv Argument vector.
 * @return Exit status (0 on success, non-zero on error).
 */
int	main(int argc, char *argv[])
{
	t_stack_holder	*stack;
	int				*numbers;

	stack = (t_stack_holder *)malloc(sizeof(t_stack_holder));
	init_empty(stack);
	if (!stack)
		return (clear_and_exit(stack, 1));
	if (argc <= 1)
		return (clear_and_exit(stack, 0));
	numbers = get_numbers(argc, argv, stack);
	if (!numbers)
	{
		return (clear_and_exit(stack, 1));
	}
	init_stack_holder(stack, numbers);
	free(numbers);
	stack->strategy = get_strategy(argc, argv);
	stack->bench = get_bench(argc, argv);
	sort(stack);
	return (clear_and_exit(stack, 0));
}
