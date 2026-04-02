#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_hex(unsigned long n, char user_case);
int	ft_putptr(uintptr_t ptr);
int	ft_putnbr_u(unsigned int n);

#endif