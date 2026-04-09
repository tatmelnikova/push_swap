#include "push_swap.h"

// calculate how many elements we want to push.
// it should be the biggest power of two, less than chunk_size
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
	
	push_to_b_count = calculate_push_size(chunk_size);
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
// every step we take chunk_size/2 elements from each stack and 
// combine them into a sorted chunk twice bigger. if chunk_size
// is not a power of two (in the end), stack B has power of two
// elements and stack A has (chunk_size - b_count) elements
void merge(t_stack_holder *sh, int chunk_size)
{
	int	from_a;
	int	from_b;
	int	take_from_a;

	from_a = 0;
	from_b = 0;
	take_from_a = chunk_size - sh->b_count;
	while(from_a + from_b < chunk_size)
		if ((from_a < take_from_a) && sh->b_count)
		{
			if (sh->a->content < sh->b->content)
				from_a = move_top_a_to_bottom_a(sh, from_a);
			else
				from_b = move_top_b_to_bottom_a(sh, from_b);
		}
		else if (from_a < take_from_a)
			from_a = move_top_a_to_bottom_a(sh, from_a);
		else if (sh->b_count)
			from_b = move_top_b_to_bottom_a(sh, from_b);
}
// chunk_size is how many elements we want to combine at each step.
// for step 1 we combine single elements, so the chunk_size = 2.
// at the 2nd step we combine pairs with sorted elements inside
// each pair, the part_size = 4
// if chunk_size == 1, it means there is just one element left,
// so no elements to divide and merge, just push it 
// to the bottom of A
void divide_merge(t_stack_holder *sh, int chunk_size)
{
	int parts_to_merge;
	int merged_count;

	parts_to_merge = sh->total / (chunk_size);
	if (sh->total % chunk_size != 0)
		parts_to_merge++;
	merged_count = 0;
	while (merged_count < parts_to_merge)
	{
		if (merged_count == parts_to_merge - 1)
			chunk_size = sh->total - (parts_to_merge - 1) * chunk_size;
		if (chunk_size == 1)
			ra(sh);
		else
		{
			divide(sh, chunk_size);
			merge(sh, chunk_size);
		}
		merged_count++;
	}
}

// call divide and merge while chunk_size is less than total.
// in the end call divide and merge again to process the tail.
// we always have a tail if total is not a power of two
t_stack_holder	*merge_sort(t_stack_holder *sh)
{
	int	chunk_size;

	chunk_size = 2;
	while (chunk_size < sh->total)
	{
		divide_merge(sh, chunk_size);
		chunk_size = chunk_size * 2;
	}
	divide_merge(sh, chunk_size);
	return (sh);
}
