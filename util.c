/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:20:27 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/21 19:20:28 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
