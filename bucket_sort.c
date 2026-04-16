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

static int	find_max_place(t_stack_holder *holder)
{
	int		i;
	int		max;
	int		index;
	t_stack	*node;

	i = 0;
	index = 0;
	max = holder->b->range;
	node = holder->b;
	while (node)
	{
		if (node->range > max)
		{
			index = i;
			max = node->range;
		}
		i++;
		node = node->next;
	}
	return (index);
}

static t_stack_holder	*return_in_stack_a(t_stack_holder *holder)
{
    int	max_index;
    int	i;

    while (holder->b_count)
    {
        max_index = find_max_place(holder);

        if (max_index <= holder->b_count / 2)
        {
            i = max_index;
            while (i-- > 0)
                rb(holder);
        }
        else
        {
            i = holder->b_count - max_index;
            while (i-- > 0)
                rrb(holder);
        }
        pa(holder);
    }
    return (holder);
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
		j = sqrt_n;
		while (holder->a_count != 0 && j > 0)
		{
			node = holder->a;
			if (node->range >= range && node->range < range + sqrt_n)
			{	
				pb(holder);
				j--;
			}
			else
				ra(holder);
		}
		range += sqrt_n;
	}
	return (return_in_stack_a(holder));
}
