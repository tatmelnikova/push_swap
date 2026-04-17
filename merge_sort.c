#include "push_swap.h"


#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

/* ===================== HELPERS ===================== */

int	find_min_pos(t_stack *stack)
{
	int min = INT_MAX, pos = 0, i = 0;

	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return pos;
}

int	find_target_pos(t_stack *a, int b_val)
{
	t_stack *curr = a;
	int pos = 0, target = 0;
	int min_diff = INT_MAX;

	while (curr)
	{
		int diff = curr->content - b_val;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target = pos;
		}
		curr = curr->next;
		pos++;
	}
	if (min_diff == INT_MAX)
		return find_min_pos(a);
	return target;
}

int	get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return pos;
	return pos - size;
}

int	abs_val(int x) { return x < 0 ? -x : x; }
int	max(int a, int b) { return a > b ? a : b; }

/* ===================== CORE ===================== */

void	find_cheapest(t_stack_holder *h, int *best_b, int *best_a)
{
	t_stack *b = h->b;
	int b_pos = 0;
	int best_cost = INT_MAX;

	while (b)
	{
		int a_pos = find_target_pos(h->a, b->content);

		int cost_a = get_cost(a_pos, h->a_count);
		int cost_b = get_cost(b_pos, h->b_count);

		int total;
		if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
			total = max(abs_val(cost_a), abs_val(cost_b));
		else
			total = abs_val(cost_a) + abs_val(cost_b);

		if (total < best_cost)
		{
			best_cost = total;
			*best_b = b_pos;
			*best_a = a_pos;
		}
		b = b->next;
		b_pos++;
	}
}

void	exec_move(t_stack_holder *sh, int a_pos, int b_pos)
{
	int ca = get_cost(a_pos, sh->a_count);
	int cb = get_cost(b_pos, sh->b_count);

	while (ca > 0 && cb > 0)
	{
		rr(sh);
		ca--; cb--;
	}
	while (ca < 0 && cb < 0)
	{
		rrr(sh);
		ca++; cb++;
	}
	while (ca > 0) { ra(sh); ca--; }
	while (ca < 0) { rra(sh); ca++; }
	while (cb > 0) { rb(sh); cb--; }
	while (cb < 0) { rrb(sh); cb++; }

	pa(sh);
}

void	final_rotate(t_stack_holder *h)
{
	int min_pos = find_min_pos(h->a);
	int cost = get_cost(min_pos, h->a_count);

	while (cost > 0) { ra(h); cost--; }
	while (cost < 0) { rra(h); cost++; }
}

/* ===================== SORT ===================== */

t_stack_holder	*merge_sort(t_stack_holder *sh){
	// push almost all to B
	while (sh->a_count > 3)
		pb(sh);

	// simple sort for 3 (you can improve)
	while (sh->b_count)
	{
		int a_pos, b_pos;
		find_cheapest(sh, &b_pos, &a_pos);
		exec_move(sh, a_pos, b_pos);
	}
	final_rotate(sh);
	return(sh);
}
