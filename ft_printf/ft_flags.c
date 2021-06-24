#include "ft_printf.h"

void	ft_flag_digit_width(int c, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = c;
}

t_flags	ft_flag_digit_point(int c, t_flags flags)
{
	if (flags.star == 1)
		flags.point = 0;
	flags.point = (c);
	return (flags);
}

t_flags	ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = ((flags.width * 10) + (c - '0'));
	return (flags);
}

void	ft_flag_width_minus(int width, int minus, int zero, t_flags *flags)
{
	width = flags->width;
	minus = flags->minus;
	zero = flags->zero;
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->minus = 1;
		flags->zero = 0;
	}
}
