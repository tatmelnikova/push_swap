#include "push_swap.h"

// check if keywords are unique for each type (we do not want
// to have two strategies). returns 0 if not
int	check_uniq_keywords(int argc, char *argv[])
{
	int	args_pos;
	int	bench;
	int	strategy;

	bench = 0;
	strategy = 0;
	args_pos = 1;
	while (args_pos < argc - 1)
	{
		if (is_keyword(argv[args_pos]))
		{
			if (!bench && is_bench(argv[args_pos]))
				bench = 1;
			else if (!strategy && is_strategy(argv[args_pos]))
				strategy = 1;
			else
				return (0);
		}
		args_pos++;
	}
	return (1);
}

// returns 0 if keywords are non valid. possible invalid inputs:
// non numeric arguments count > 3 (we cannot have more than 2 flags)
// non numeric count = argc (all arguments are flags, no numbers)
// some keywords are not unique (e.g. two strategies given)
int	validate_keywords(int non_num_count, int argc, char *argv[])
{
	if (non_num_count > 3 || !check_uniq_keywords(argc, argv))
		return (0);
	if (argc == non_num_count)
		return (0);
	return (1);
}