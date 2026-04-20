#include "push_swap.h"

/**
 * @brief Determines which sorting strategy to use.
 *
 * This function scans the provided command-line arguments and selects
 * a strategy flag depending on the presence of specific option strings:
 *
 *   --simple   → O(n²) algorithm (SIMPLE)
 *   --medium   → O(n√n) algorithm (MEDIUM)
 *   --complex  → O(n log n) algorithm (COMPLEX)
 *
 * If none of these flags are found, the function defaults to ADAPTIVE,
 * which selects an algorithm dynamically based on input disorder.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line argument strings.
 * @return int An integer constant representing the chosen strategy:
 *         SIMPLE, MEDIUM, COMPLEX, or ADAPTIVE (default).
 */
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

/**
 * @brief This function scans the command-line arguments for the presence of
 * the "--bench" flag. If found, benchmarking mode is enabled.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line argument strings.
 * @return int 1 if the "--bench" flag is present, 0 otherwise.
 */
int	get_bench(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (is_bench(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
