#include "push_swap.h"

int	is_keyword(char *word)
{
	return (!strcmp(word, "--simple") || !strcmp(word, "--medium") || !strcmp(word, "--complex") 
			|| !strcmp(word, "--adaptive") || !strcmp(word, "--bench"));
}