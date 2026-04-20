#include "push_swap.h"

int	is_keyword(char *word)
{
	return (!ft_strcmp(word, "--simple") || !ft_strcmp(word, "--medium")
		|| !ft_strcmp(word, "--complex") || !ft_strcmp(word, "--adaptive")
		|| !ft_strcmp(word, "--bench" ));
}

int	is_bench(char *word)
{
	return (!ft_strcmp(word, "--bench" ));
}

int	is_strategy(char *word)
{
	return (!ft_strcmp(word, "--simple") || !ft_strcmp(word, "--medium")
		|| !ft_strcmp(word, "--complex") || !ft_strcmp(word, "--adaptive"));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
