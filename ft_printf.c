#include "ft_printf.h"

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

int	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

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

int	conversion(int fd, char c, va_list *args)
{
	if (c == 's')
		return (ft_putstr(fd, va_arg(*args, char *)));
	else if (c == 'd')
		return (ft_putnbr(fd, va_arg(*args, int)));
	return (-1);
}

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
