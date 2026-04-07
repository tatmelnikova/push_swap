#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(int fd, const char *str, ...);
int	ft_putchar(int fd, char c);
int	ft_putstr(int fd, char *s);
int	ft_putnbr(int fd, int n);
int	ft_putnbr_hex(int fd, unsigned long n, char user_case);
int	ft_putptr(int fd, uintptr_t ptr);
int	ft_putnbr_u(int fd, unsigned int n);

#endif