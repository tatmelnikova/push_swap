#include "push_swap.h"

// converts char* s_number and writes the value into number[i]
// returns 0 on fail
static int	add_number(char *s_number, int *numbers, int i)
{
	int	j;
	int	*n;

	j = 0;
	n = ft_atoi(s_number);
	if (!n)
		return (0);
	while (j < i)
	{
		if (numbers[j] == *n)
		{
			free(n);
			return (0);
		}
		j++;
	}
	numbers[i] = *n;
	free(n);
	return (1);
}

int	*parse_numbers(char **s_numbers, int size)
{
	int	*numbers;
	int	i;
	int	j;
	int	added;

	i = 0;
	j = 0;
	numbers = malloc(sizeof(int *) * size);
	if (!numbers)
		return (NULL);
	while (j < size)
	{
		if (!is_keyword(s_numbers[i]))
		{
			added = add_number(s_numbers[i], numbers, j++);
			if (!added)
			{
				free(numbers);
				return (NULL);
			}
		}
		i++;
	}
	return (numbers);
}

int	count_non_numeric_args(int argc, char *argv[])
{
	int	args_pos;
	int	had_numbers;
	int	keywords_count;

	args_pos = 1;
	keywords_count = 1;
	had_numbers = 0;
	while (args_pos < argc)
	{
		if (is_keyword(argv[args_pos]) && !had_numbers)
		{
			keywords_count++;
		}
		else if (is_keyword(argv[args_pos]) && had_numbers)
		{
			had_numbers = -1;
			keywords_count++;
		}
		else if (!is_keyword(argv[args_pos]) && had_numbers == -1)
			return (-1);
		else
			had_numbers = 1;
		args_pos++;
	}
	return (keywords_count);
}

int	*get_numbers(int argc, char *argv[], t_stack_holder *sh)
{
	int		*numbers;
	int		non_num_count;
	int		size;
	char	**splited_num;

	non_num_count = count_non_numeric_args(argc, argv);
	if (!validate_keywords(non_num_count, argc, argv))
		return (NULL);
	if (argc - non_num_count > 1)
	{
		numbers = parse_numbers(&argv[1], argc - non_num_count);
		size = argc - non_num_count;
	}
	else
	{
		if (!validate_numbers_string(argv[non_num_count]))
			return (NULL);
		size = count_words(argv[non_num_count], ' ');
		splited_num = ft_split(argv[non_num_count], ' ');
		numbers = parse_numbers(splited_num, size);
		free_arr(size, splited_num);
	}
	sh->total = size;
	return (numbers);
}
