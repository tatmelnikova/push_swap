/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorenev <skorenev@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:23:29 by skorenev          #+#    #+#             */
/*   Updated: 2026/04/21 19:23:30 by skorenev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Counts the number of words in a string separated by a delimiter.
 *
 * @param s Input null-terminated string.
 * @param c Delimiter character.
 * @return Number of words found in the string.
 */
int	count_words(char const *s, char c)
{
	size_t	i;
	int		count;
	int		is_first_letter;

	i = 0;
	count = 0;
	is_first_letter = 1;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
			is_first_letter = 1;
		else if (s[i] != c && is_first_letter)
		{
			count++;
			is_first_letter = 0;
		}
		i++;
	}
	return (count);
}

/**
 * @brief Measures the number of characters in a substring starting from `s`
 * until the delimiter character `c` or the end of the string.
 * 
 * @param s Input string starting at a word.
 * @param c Delimiter character.
 * @return Length of the word.
 */
static int	find_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

/**
 * @brief Copies a word from the source string into a newly allocated buffer.
 *
 * @param s     Source string.
 * @param c     Delimiter character.
 * @param word  Destination buffer where the word is stored.
 * @param count Pointer to index tracker in the original string.
 *
 * @return Pointer to the filled word buffer.
 */
static char	*fill_word(char const *s, char c, char *word, int *count)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	*count += i;
	word[i] = '\0';
	return (word);
}

/**
 * @brief Frees a partially allocated array of strings.
 *
 * Frees all allocated strings in the array up to index `j`, then frees
 * the array itself.
 * @param j             Last valid index in the array.
 * @param splited_words Null-terminated array of strings to free.
 * @return Always returns NULL for convenience in error handling.
 */
char	**free_arr(int j, char **splited_words)
{
	while (--j >= 0)
		free(splited_words[j]);
	free(splited_words);
	return (NULL);
}

/**
 * @brief Allocates memory (using malloc(3)) and returns an array of strings 
 * obtained by splitting ’s’ using the character ’c’ as a delimiter. 
 * Each string in the returned array is allocated independently. The array 
 * of pointers itself is also allocated dynamically. The returned array 
 * must be NULL terminated.
 * 
 * @param s The string to be split
 * @param c The delimiter character.
 * @return * char** The array of new strings resulting from the split. 
 * NULL if any allocation fails.The returned structure will be released 
 * using: 1)free() on each string in the array; 2) free() thearray itself.
 */
char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**splited_words;
	char	*word;

	i = 0;
	j = 0;
	splited_words = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!splited_words)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word = malloc(find_word_len(&s[i], c) + 1);
			if (!word)
				return (free_arr(j, splited_words));
			fill_word(&s[i], c, word, &i);
			splited_words[j++] = word;
		}
	}
	splited_words[j] = NULL;
	return (splited_words);
}
