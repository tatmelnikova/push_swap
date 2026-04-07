#include "ft_printf.h"

int	conversion(int fd, char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(fd, va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(fd, va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(fd, va_arg(*args, int)));
	else if (c == 'p')
		return (ft_putptr(fd, va_arg(*args, uintptr_t)));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr_hex(fd, va_arg(*args, unsigned int), c));
	else if (c == 'u')
		return (ft_putnbr_u(fd, va_arg(*args, unsigned int)));
	else if (c == '%')
		return (ft_putchar(fd, '%'));
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
