#include "push_swap.h"

static void	add_number(char **s_numbers, int *numbers, int i)
{
	int j;
	int n;

	if (is_keyword(s_numbers[i]))
		return ;
	j = 0;
	n = ft_atoi(s_numbers[i]);
	while (j < i)
	{
		if (numbers[j] == n)
			error();
		j++;
	}
	numbers[i] = n;
}

int	*parse_numbers(char **s_numbers, int size)
{
	int	*numbers;
	int	i;
	int	num_count;

	i = 0;
	num_count = size;
	while (i < size)
	{
		if (is_keyword(s_numbers[i]))
			num_count--;
		i++;
	}
	numbers = malloc(sizeof(int *) * num_count);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < size)
	{	
		add_number(s_numbers, numbers, i);
		i++;
	}
	return (numbers);
}
