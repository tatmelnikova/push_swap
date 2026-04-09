#include "push_swap.h"

int	calculate_push_size(int chunk_size)
{
	int	power;

	if (chunk_size == 1)
		return (0);

	power = 2;
	while (power < chunk_size)
	{
		power = power * 2;
	}
	power = (power / 2);
	return (power);
}

// push the next group of elements to stack B (should be empty 
// at start). each element should be moved down after it's pushed,
// so the minimum is always at the top of the stack
// chunk size is 2* part_size or less, if there are no more 
// elements left
void	divide(t_stack_holder *sh, int chunk_size)
{
	int	count;
	int push_to_b_count;
	//int rb_count;

	//rb_count = 0;
	if (chunk_size == 1)
	{
		ra(sh);
		return ;
	}
	
	push_to_b_count = calculate_push_size(chunk_size);
	//ft_printf(STDOUT_FILENO, "push b size = %d\n", push_to_b_count);
	count = 0;
	while (count < push_to_b_count)
	{
		pb(sh);
		if (sh->b_count > 1)
		{
			rb(sh);
		}
		count++;
	}
}


// merge elements from both stacks, the minimum is always at top,
// so we take the min from one stack and move it to stack A bottom.
// every step we take chunk_size/2 elements and combine them into a sorted
// chunk twice bigger
void merge(t_stack_holder *sh, int chunk_size)
{
	int	from_a;
	int	from_b;
	int	b_count;
	int	take_from_a;

	from_a = 0;
	from_b = 0;

	
	b_count = sh->b_count;
	take_from_a = chunk_size - b_count;
	//printf("chunk_size = %d, b_count = %d, take_from_a = %d\n", chunk_size, b_count, take_from_a);
	if (chunk_size == 1)
		return ;
	while(from_a + from_b < chunk_size)
	{
		if ((from_a < take_from_a) && b_count)
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
		else if (from_a < take_from_a)
		{
			ra(sh);
			from_a++;
		}
		else if (sh->b_count)
		{
			pa(sh);
			ra(sh);
			from_b++;
		}
		b_count = sh->b_count;
	}

}
// part size - how many elements we want to combine at each step.
// for step 1 we combine single elements, so the part_size = 1.
// at the 2nd step we combine pairs with sorted elements inside
// each pair, the part_size = 2
void divide_merge(t_stack_holder *sh, int chunk_size)
{
	int parts_to_merge;
	int merged_count;

	//printf("start divide_merge, part_size = %d\n", chunk_size);
	//print_stack_holder(sh);
	parts_to_merge = sh->total / (chunk_size);
	if (sh->total % chunk_size != 0)
		parts_to_merge++;
	merged_count = 0;
	while (merged_count < parts_to_merge)
	{
		if (merged_count == parts_to_merge - 1)
			chunk_size = sh->total - (parts_to_merge - 1) * chunk_size;
		divide(sh, chunk_size);
		//printf("divided result, chunk_size = %d\n", chunk_size);
		//print_stack_holder(sh);
		merge(sh, chunk_size);
		//printf("merged result, chunk_size = %d\n", chunk_size);
		//print_stack_holder(sh);
		merged_count++;
	}
}

t_stack_holder *merge_sort(t_stack_holder *sh)
{
	int	part_size;

	part_size = 2;
	while (part_size < sh->total)
	{
		divide_merge(sh, part_size);
		//move_tail(sh, part_size);
		part_size = part_size * 2;
	}
	divide_merge(sh, part_size);
	//ft_printf(STDOUT_FILENO, "result = \n");
	//int result = sort_check(sh);
	//printf("sorted = %d\n", result);
	return (sh);
}
