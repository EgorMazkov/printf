#include "ft_printf.h"

int	ft_treat_char(char i, t_flags *flags)
{
	if (flags->minus == 1)
	{
		ft_putchar_fd(i, flags);
		flags->len_word = ft_flag_width(flags->width, \
		flags->minus, flags->zero, flags);
	}
	else if (flags->width && flags->type == '%' && !flags->minus)
	{
		flags->len_word = ft_flag_width(flags->width, \
		flags->minus, flags->zero, flags);
	}
	if (flags->minus == 0)
	{
		flags->width--;
		flags->len_word = ft_flag_width(flags->width, \
		flags->minus, flags->zero, flags);
		ft_putchar_fd(i, flags);
	}
	return (flags->len_word);
}
