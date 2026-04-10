#include "push_swap.h"

static	int	ft_sqrt(int nb)
{
	int				middle;
	int				left;
	int				rigth;
	unsigned long	sqrt;
	unsigned long	nb_long;

	left = 0;
	rigth = nb;
	nb_long = nb;
	if (nb < 0)
		return (0);
	while (left <= rigth)
	{
		middle = (rigth + left) / 2;
		sqrt = middle * middle;
		if (sqrt == nb_long)
			return (middle);
		else if (sqrt > nb_long)
			rigth = middle - 1;
		else
			left = middle + 1;
	}
	return (rigth);
}

static void	push_and_check(t_stack_holder *holder)
{
	int 	i;
	t_stack	*first;
	t_stack	*second;

	i = 0;
	pb(holder);
	while (1)
	{
		first = holder->b;
		if (!first->next)
			return ;
		second = first->next;
		if (first->content < second->content)
		{
			sb(holder);
			pa(holder);
			i++;
		}
		else
			break ;
	}
	while (i > 0)
	{
		pb(holder);
		i--;
	}
}


static void	find_rang(t_stack_holder *holder)
{
	int		range;
	t_stack	*node;
	t_stack	*compare_node;
	
	node = holder->a;
	while (node)
	{
		range = 0;
		compare_node = holder->a;
		while (compare_node)
		{
			if (node->content > compare_node->content)
				range++;
			compare_node = compare_node->next;
		}
		node->range = range;
		node = node->next;
	}
}

t_stack_holder	*bucket_sort(t_stack_holder *holder)
{
	int	j;
	int	range;
	int	sqrt_n;
	t_stack	*node;

	range = 0;
	sqrt_n = ft_sqrt(holder->a_count);
	find_rang(holder);
	while (holder->a_count)
	{
		j = holder->a_count;
		while (j > 0)
		{
			node = holder->a;
			if (node->range >= range && node->range < range + sqrt_n)
				push_and_check(holder);
			else
				ra(holder);
			j--;
		}
		range += sqrt_n;
	}
	return_in_stack_a(holder);
	return (holder);
}
