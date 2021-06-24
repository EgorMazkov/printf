#include "ft_printf.h"

int	width_minus(unsigned int h, int len, t_flags *flags)
{
	if (h == 0 && flags->width && !flags->minus)
	{
		len = 1;
		flags->width -= len;
		ft_flag_width(flags->width, 0, flags->zero, flags);
		ft_putstr_fd(("0"), flags);
		flags->width = 0;
	}
	return (flags->len_word);
}

int	width(unsigned int h, int len, t_flags *flags)
{
	if (flags->width)
	{
		flags->width -= len;
		ft_flag_width(flags->width, 0, flags->zero, flags);
		hexa_dis_sys(h, flags);
	}
	return (flags->len_word);
}

int	width_point(unsigned int h, int len, t_flags *flags)
{
	if (flags->width && flags->point)
	{
		if (flags->width)
		{
			if (flags->point < len)
			{
				flags->width -= len;
				flags->point = 0;
			}
			flags->width -= flags->point;
			ft_flag_width(flags->width, 0, 0, flags);
		}
		if (flags->point)
		{
			flags->point -= len;
			while (flags->point != 0)
			{
				ft_putchar_fd('0', flags);
				flags->point--;
			}
		}
		hexa_dis_sys(h, flags);
	}
	return (flags->len_word);
}

int	minus_width_h(unsigned int h, int len, t_flags *flags)
{
	if (flags->minus && flags->width && h != 0)
	{
		if (h == 0)
			ft_putstr_fd("0", flags);
		else
			hexa_dis_sys(h, flags);
		flags->minus = 0;
		if (flags->width)
		{
			flags->width -= len;
			ft_flag_width(flags->width, 0, flags->zero, flags);
		}
		flags->width = 0;
	}
	return (flags->len_word);
}
