#include "push_swap.h"

void	print_operations(t_stack_holder *sh)
{
	char *ops[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	int	op_count  = 11;
	int	counter;

	counter = 0;
	while(counter < op_count)
	{
		ft_printf(STDERR_FILENO, "[bench] ");
		ft_printf(STDERR_FILENO, "%s: %d\n", ops[counter], get_op_count(sh->operations, ops[counter]));
		counter++;
	}
}

void	print_total(t_stack_holder *sh)
{
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "total_ops: %d\n", get_op_count(sh->operations, NULL));
}

// ◦ The computed disorder (% with two decimals).
// ◦ The name of the strategy used and its theoretical complexity class.
// ◦ The total number of operations.
// ◦ The count of each operation type (sa, sb, ss, pa, pb, ra, rb,
//   rr, rra, rrb, rrr).
void print_bench(t_stack_holder *sh)
{
	print_disorder(sh->disorder);
	print_operations(sh);
	print_total(sh);
}

//disorder: 49.93%
void	print_disorder(float disorder)
{
	int	i_disorder;

	i_disorder = (int) disorder;
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "disorder: %d.%d%%\n", i_disorder, (int)((disorder - i_disorder) * 100));
}


