#include "push_swap.h"

static int	is_keyword(char *word)
{
	return (!strcmp(word, "--simple") || !strcmp(word, "--medium") || !strcmp(word, "--complex") 
			|| !strcmp(word, "--adaptive") || !strcmp(word, "--bench"));
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
		if (!is_keyword(s_numbers[i]))
			numbers[i] = ft_atoi(s_numbers[i]);
		i++;
	}
	return (numbers);
}
