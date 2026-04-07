#include "ft_printf.h"

int	ft_putptr(int fd, uintptr_t ptr)
{
	int	len;

	if (!ptr)
		return (ft_putstr(fd, "(nil)"));
	ft_putstr(fd, "0x");
	len = 2 + ft_putnbr_hex(fd, ptr, 'x');
	return (len);
}

int	ft_putnbr_hex(int fd, unsigned long n, char user_case)
{
	int		len;
	char	*base;

	len = 0;
	if (user_case == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
		len += ft_putnbr_hex(fd, n / 16, user_case);
	ft_putchar(fd, base[n % 16]);
	len++;
	return (len);
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

int	ft_putnbr_u(int fd, unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n > 9)
		len += ft_putnbr_u(fd, n / 10);
	c = (n % 10) + '0';
	ft_putchar(fd, c);
	return (++len);
}
