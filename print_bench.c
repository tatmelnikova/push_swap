#include "push_swap.h"

void	print_operations(t_stack_holder *sh)
{
	char *ops[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	int	op_count  = 11;
	int	counter;

	counter = 0;
	ft_printf(STDERR_FILENO, "[bench] ");
	while(counter < op_count)
	{
		if (counter == 5)
		{
			ft_printf(STDERR_FILENO, "\n");
			ft_printf(STDERR_FILENO, "[bench] ");
		}
		ft_printf(STDERR_FILENO, "%s: %d  ", ops[counter], get_op_count(sh->operations, ops[counter]));
		counter++;
	}
	ft_printf(STDERR_FILENO, "\n");
}

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
	print_strategy(sh);
	print_total(sh);
	print_operations(sh);
}

//disorder: 49.93%
void	print_disorder(float disorder)
{
	int	i_disorder;

	i_disorder = (int) disorder;
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "disorder: %d.%d%%\n", i_disorder, (int)((disorder - i_disorder) * 100));
}


