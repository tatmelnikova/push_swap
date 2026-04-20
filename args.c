#include "push_swap.h"

// An optional strategy selector:
// --simple Forces the use of your O(n * n) algorithm.
// --medium Forces the use of your O(n √ n) algorithm.
// --complex Forces the use of your O(n log n) algorithm.
// --adaptive Forces the use of your adaptive algorithm
// based on disorder. This is the default behavior if no
// selector is given.
int	get_strategy(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--simple"))
			return (SIMPLE);
		if (!ft_strcmp(argv[i], "--medium"))
			return (MEDIUM);
		if (!ft_strcmp(argv[i], "--complex"))
			return (COMPLEX);
		i++;
	}
	return (ADAPTIVE);
}

int	get_bench(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--bench"))
			return (1);
		i++;
	}
	return (0);
}

void	print_args(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		printf("arg[%d] = %s\n", i, argv[i]);
		i++;
	}
}

int	validate_numbers_string(char *num_str)
{
	while (*num_str)
	{
		if ((*num_str < '0' || *num_str > '9') && (*num_str != ' '))
			return (0);
		num_str++;
	}
	return (1);
}
