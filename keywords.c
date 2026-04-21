/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keywords.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:17:08 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/21 19:17:10 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if a string is a valid program keyword.
 *
 * Valid keywords include:
 * - --simple
 * - --medium
 * - --complex
 * - --adaptive
 * - --bench
 * @param word Input string to check.
 * @return 1 if the string is a recognized keyword, 0 otherwise.
 */
int	is_keyword(char *word)
{
	return (!ft_strcmp(word, "--simple") || !ft_strcmp(word, "--medium")
		|| !ft_strcmp(word, "--complex") || !ft_strcmp(word, "--adaptive")
		|| !ft_strcmp(word, "--bench" ));
}

/**
 * @brief Checks if a string is the benchmark keyword.
 *
 * Determines whether the input matches "--bench".
 * @param word Input string to check.
 * @return 1 if the string is "--bench", 0 otherwise.
 */
int	is_bench(char *word)
{
	return (!ft_strcmp(word, "--bench" ));
}

/**
 * @brief Checks if a string is a valid sorting strategy keyword.
 *
 * Valid strategies include:
 * - --simple
 * - --medium
 * - --complex
 * - --adaptive
 * @param word Input string to check.
 * @return 1 if the string is a strategy keyword, 0 otherwise.
 */
int	is_strategy(char *word)
{
	return (!ft_strcmp(word, "--simple") || !ft_strcmp(word, "--medium")
		|| !ft_strcmp(word, "--complex") || !ft_strcmp(word, "--adaptive"));
}

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
	if (non_num_count < 0)
		return (0);
	return (1);
}