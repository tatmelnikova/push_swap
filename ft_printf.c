#include "push_swap.h"

/**
 * @brief Writes a string to a given file descriptor.
 *
 * Outputs a null-terminated string to the specified file descriptor.
 * If the input string is NULL, the literal string "(null)" is printed instead.
 * @param fd File descriptor where the string is written.
 * @param s  Null-terminated string to print.
 * @return Number of characters written.
 */
int	ft_putstr(int fd, char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

/**
 * @brief Writes a single character to a given file descriptor.
 * 
 * @param fd File descriptor where the character is written.
 * @param c  Character to print.
 * @return Always returns 1 (one character written).
 */
int	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

/**
 * @brief Prints an integer to a given file descriptor.
 *
 * Outputs a signed integer by recursively processing each digit.
 * Negative numbers are handled by printing a '-' sign and converting
 * the value to its absolute representation.
 * The function prints digits using recursion and outputs characters
 * using ft_putchar().
 * @param fd File descriptor where the number is written.
 * @param n  Integer value to be printed.
 * @return The number of characters written.
 */
int	ft_putnbr(int fd, int n)
{
	long	num_l;
	char	c;
	int		len;

	len = 0;
	num_l = n;
	if (num_l < 0)
	{
		num_l *= -1L;
		write(1, "-", 1);
		len++;
	}
	if (num_l > 9)
		len += ft_putnbr(fd, (int)(num_l / 10));
	c = (num_l % 10) + '0';
	ft_putchar(fd, c);
	return (++len);
}

/**
 * @brief Handles format specifier conversion for ft_printf.
 *
 * Supported specifiers:
 * - 's' : prints a string (char *)
 * - 'd' : prints a signed integer (int)
 * @param fd    File descriptor where output is written.
 * @param c     Format specifier character ('s', 'd', etc.).
 * @param args  Pointer to the variable argument list.
 * @return Number of characters written for the converted argument,
 *         or -1 if the specifier is invalid or a conversion fails.
 */
int	conversion(int fd, char c, va_list *args)
{
	if (c == 's')
		return (ft_putstr(fd, va_arg(*args, char *)));
	else if (c == 'd')
		return (ft_putnbr(fd, va_arg(*args, int)));
	else if (c == '%')
        return (ft_putchar(fd, '%'));
	return (-1);
}

/**
 * @brief Custom formatted output function similar to printf.
 *
 * Writes a formatted string to the given file descriptor, supporting
 * format specifiers introduced by '%' and handled via a variable
 * argument list.
 * @param fd    File descriptor where output is written.
 * @param str   Format string containing plain text and format specifiers.
 * @param ...   Variable arguments corresponding to format specifiers.
 * @return Total number of characters written on success,
 *         or -1 if an error occurs (invalid format or conversion failure).
 */
int	ft_printf(int fd, const char *str, ...)
{
	int		i;
	int		result;
	int		check;
	va_list	args;

	i = 0;
	result = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			else
				check = conversion(fd, str[++i], &args);
			if (check == -1)
				return (-1);
			result += check;
		}
		else
			result += ft_putchar(fd, str[i]);
		i++;
	}
	return (result);
}
