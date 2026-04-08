#include "push_swap.h"

void	divide(t_stack_holder *sh, int part_size)
{
	int	count;
	//int rb_count;

	//rb_count = 0;
	count = 0;
	while (count < part_size)
	{
		pb(sh);
		if (sh->b_count > 1)
		{
			rb(sh);
		}
		count++;
	}
}

void merge(t_stack_holder *sh, int part_size)
{
	int	from_a;
	int	from_b;

	from_a = 0;
	from_b = 0;
	while(from_a + from_b < part_size * 2)
	{
		if (from_a < part_size && from_b < part_size)
		{
			if (sh->a->content < sh->b->content)
			{
				ra(sh);
				from_a++;
			}
			else
			{
				pa(sh);
				ra(sh);
				from_b++;
			}
		}
		else if (from_a < part_size)
		{
			ra(sh);
			from_a++;
		}
		else if (from_b < part_size)
		{
			pa(sh);
			ra(sh);
			from_b++;
		}
	}

}

void divide_merge(t_stack_holder *sh, int part_size)
{
	int parts_to_merge;
	int merged_count;

	printf("start divide_merge, part_size = %d\n", part_size);
	print_stack_holder(sh);
	parts_to_merge = sh->total / (part_size * 2);
	merged_count = 0;
	while (merged_count < parts_to_merge)
	{
		divide(sh, part_size);
		print_stack_holder(sh);
		merge(sh, part_size);
		print_stack_holder(sh);
		merged_count++;
	}
	
}

void	move_tail(t_stack_holder *sh, int part_size)
{
	int	tail_count;
	int	i;

	i = 0;
	tail_count = sh->total % (part_size * 2);
	while(i < tail_count)
	{
		ra(sh);
		i++;
	}
}

t_stack_holder *merge_sort(t_stack_holder *sh)
{
	int	part_size;

	part_size = 1;
	while (part_size < sh->total / 2)
	{
		divide_merge(sh, part_size);
		move_tail(sh, part_size);
		part_size = part_size * 2;
	}
	ft_printf(STDOUT_FILENO, "result = ");
	print_stack_holder(sh);

	// int test = 0;
	// while (test < 500)
	// {
	// 	printf("%d ", test);
	// 	test++;
	// }
	return (sh);
}
