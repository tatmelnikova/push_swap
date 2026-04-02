#include "ft_printf.h"

int	ft_putptr(uintptr_t ptr)
{
	int	len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	len = 2 + ft_putnbr_hex(ptr, 'x');
	return (len);
}

int	ft_putnbr_hex(unsigned long n, char user_case)
{
	int		len;
	char	*base;

	len = 0;
	if (user_case == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
		len += ft_putnbr_hex(n / 16, user_case);
	ft_putchar(base[n % 16]);
	len++;
	return (len);
}

int	ft_putnbr(int n)
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
		len += ft_putnbr((int)(num_l / 10));
	c = (num_l % 10) + '0';
	ft_putchar(c);
	return (++len);
}

int	ft_putnbr_u(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n > 9)
		len += ft_putnbr_u(n / 10);
	c = (n % 10) + '0';
	ft_putchar(c);
	return (++len);
}
