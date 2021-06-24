#include "ft_printf.h"

int	ft_treat_percent(int h, t_flags *flags)
{
	int	len;

	len = 1;
	if (!h)
		return (flags->len_word);
	if (flags->width && !flags->zero && !flags->point && !flags->minus)
	{
		flags->width -= len;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		ft_putchar_fd('%', flags);
	}
	else if (flags->width && flags->minus && !flags->zero)
	{
		ft_putchar_fd('%', flags);
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
	}
	else if (flags->zero && flags->width)
	{
		flags->width -= len;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		ft_putchar_fd('%', flags);
	}
	else if (!flags->width && !flags->minus && !flags->minus)
		ft_putchar_fd('%', flags);
	return (flags->len_word);
}
