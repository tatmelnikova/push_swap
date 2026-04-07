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
