#include "push_swap.h"

/**
 * @brief Prints a summary of all operation counts.
 *
 * Displays how many times each push_swap operation was executed,
 * grouped in two lines for readability.
 * @param sh Pointer to the stack holder containing the operations list.
 */
void	print_operations(t_stack_holder *sh)
{
	char	*ops[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	int		op_count;
	int		counter;

	op_count = 11;
	counter = 0;
	ft_printf(STDERR_FILENO, "[bench] ");
	while (counter < op_count)
	{
		if (counter == 5)
		{
			ft_printf(STDERR_FILENO, "\n");
			ft_printf(STDERR_FILENO, "[bench] ");
		}
		ft_printf(STDERR_FILENO, "%s: %d  ",
			ops[counter], get_op_count(sh->operations, ops[counter]));
		counter++;
	}
	ft_printf(STDERR_FILENO, "\n");
}

/**
 * @brief Prints the selected and available sorting strategy.
 *
 * Displays whether adaptive mode is enabled and which strategy
 * was ultimately chosen (simple, medium, or complex).
 * @param sh Pointer to the stack holder containing strategy information.
 */
void	print_strategy(t_stack_holder *sh)
{
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "strategy: ");
	if (sh->strategy == ADAPTIVE)
		ft_printf(STDERR_FILENO, "adaptive / ");
	if (sh->chosen_strategy == SIMPLE)
		ft_printf(STDERR_FILENO, "simple");
	else if (sh->chosen_strategy == COMPLEX)
		ft_printf(STDERR_FILENO, "complex");
	else if (sh->chosen_strategy == MEDIUM)
		ft_printf(STDERR_FILENO, "medium");
	ft_printf(STDERR_FILENO, "\n");
}

/**
 * @brief Prints the total number of operations executed.
 *
 * Counts all recorded operations in the operations list and outputs
 * the total.
 * @param sh Pointer to the stack holder containing operations list.
 */
void	print_total(t_stack_holder *sh)
{
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "total_ops: %d\n",
		get_op_count(sh->operations, NULL));
}

/**
 * @brief Prints full benchmark summary.
 *
 * Outputs a complete benchmark report including:
 * - disorder percentage
 * - selected strategy
 * - total number of operations
 * - breakdown of all operation types
 * @param sh Pointer to the stack holder containing benchmark data.
 */
void	print_bench(t_stack_holder *sh)
{
	print_disorder(sh->disorder);
	print_strategy(sh);
	print_total(sh);
	print_operations(sh);
}

/**
 * @brief Prints the disorder percentage of the dataset.
 *
 * Displays how disordered the input is in percentage format
 * with two decimal precision.
 * @param disorder Floating-point value representing disorder percentage.
 */
void	print_disorder(float disorder)
{
	int	i_disorder;

	i_disorder = (int) disorder;
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "disorder: %d.%d%%\n",
		i_disorder, (int)((disorder - i_disorder) * 100));
}
