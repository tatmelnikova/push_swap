#include "push_swap.h"

int	*parse_numbers(char **s_numbers, int size)
{
	int	*numbers;
	int	i;

	i = 0;
	numbers = malloc(sizeof(int *) * size);
	if (!numbers)
		return (NULL);
	while (i < size)
	{
		numbers[i] = ft_atoi(s_numbers[i]);
		i++;
	}
	return (numbers);
}
