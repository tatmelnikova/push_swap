/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorenev <skorenev@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:41:28 by skorenev          #+#    #+#             */
/*   Updated: 2026/04/15 13:54:30 by skorenev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * @brief converts string number into integer. 
 Works with numbers from min_int to max_int. 
 Skip all spaces. Allow one plus or minus.
 * 
 * @param nptr 
 * @return the converted value or en error. 
 */
int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = (result * 10) + nptr[i] - '0';
		i++;
	}
	if (sign * result < INT_MIN || sign * result > INT_MAX || nptr[i] != '\0')
		print_error();
	return ((int)(sign * result));
}

