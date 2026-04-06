#include "push_swap.h"

// An optional strategy selector:
// --simple Forces the use of your O(n * n) algorithm.
// --medium Forces the use of your O(n √ n) algorithm.
// --complex Forces the use of your O(n log n) algorithm.
// --adaptive Forces the use of your adaptive algorithm 
// based on disorder. This is the default behavior if no
// selector is given.

int get_strategy(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{		
		if (argv[i] == 0)
		 	return (SIMPLE);
		// if (argv[i] == "--medium")
		// 	return (MEDIUM);
		// if (argv[i] == "--complex")
		// 	return (COMPLEX);
		i++;
	}
	return (ADAPTIVE);
}
