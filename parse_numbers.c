#include "push_swap.h"

static void	add_number(char *s_number, int *numbers, int i)
{
	int	j;
	int	n;

	j = 0;
	n = ft_atoi(s_number);
	while (j < i)
	{
		if (numbers[j] == n)
			print_error();
		j++;
	}
	numbers[i] = n;
}

int	*parse_numbers(char **s_numbers, int size)
{
	int	*numbers;
	int	i;
	int	j;

	i = 0;
	j = 0;
	numbers = malloc(sizeof(int *) * size);
	if (!numbers)
		return (NULL);
	while (j < size)
	{
		if (!is_keyword(s_numbers[i]))
			add_number(s_numbers[i], numbers, j++);
		i++;
	}
	return (numbers);
}
