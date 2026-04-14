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

	i = 0;
	ft_printf(1, "\n!!!size = %d\n", size);
	numbers = malloc(sizeof(int *) * size);
	if (!numbers)
		return (NULL);
	while (s_numbers[i])
	{	
		if (is_keyword(s_numbers[i]))
			continue ;
		add_number(s_numbers, numbers, i);
		i++;
	}
	return (numbers);
}
