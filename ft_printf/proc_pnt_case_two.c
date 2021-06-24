#include "ft_printf.h"

void	width_pnt(char *dest, unsigned long long h, int len, t_flags *flags)
{
	if (flags->width)
	{
		if (flags->width > len)
			flags->width -= len;
		else
			flags->width = 0;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		ft_count_putstr(dest, h, flags);
	}
}

void	minus_width_pnt(char *dest, unsigned long long h, \
int len, t_flags *flags)
{
	if (flags->minus && flags->width)
	{
		flags->minus = 0;
		flags->width -= len;
		ft_count_putstr(dest, h, flags);
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
	}
}
