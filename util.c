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

/**
 * @brief Compares two strings lexicographically.
 *
 * Mimics standard strcmp behavior by comparing characters until a
 * difference or null terminator is found.
 * @param s1 First string.
 * @param s2 Second string.
 * @return 0 if strings are equal,
 *         negative value if s1 < s2,
 *         positive value if s1 > s2.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
