#include "ft_printf.h"

int	width_point_h(unsigned int h, int len, t_flags *flags)
{
	if (flags->width && flags->point && h == 0)
	{
		if (flags->width)
		{
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
			hexa_dis_sys(h, flags);
		}
		flags->width = 0;
		flags->point = 0;
	}
	return (flags->len_word);
}

int	point_minus(unsigned int h, int len, t_flags *flags)
{
	if (flags->point && flags->minus)
	{
		flags->minus = 0;
		flags->point -= len;
		while (flags->point != 0)
		{
			ft_putchar_fd('0', flags);
			flags->point--;
		}
		hexa_dis_sys(h, flags);
	}
	return (flags->len_word);
}

int	point(unsigned int h, int len, t_flags *flags)
{
	if (flags->point)
	{
		if (flags->point > len)
		{
			flags->point -= len;
			while (flags->point != 0)
			{
				ft_putchar_fd('0', flags);
				flags->point--;
			}
			hexa_dis_sys(h, flags);
		}
		else
			hexa_dis_sys(h, flags);
	}
	return (flags->len_word);
}

int	minus_width_point(unsigned int h, int len, t_flags *flags)
{
	if (flags->point)
	{
		if (flags->point <= len && flags->point <= flags->width)
		{
			flags->point = 0;
		}
		if (flags->point != 0)
		{
			flags->point -= len;
			flags->width -= flags->point;
		}
		while (flags->point != 0)
		{
			ft_putchar_fd('0', flags);
			flags->point--;
		}
		hexa_dis_sys(h, flags);
	}
	if (flags->width)
	{
		flags->width -= len;
		ft_flag_width(flags->width, 0, flags->zero, flags);
	}
	return (flags->len_word);
}

int	minus_width_h_pointer(unsigned int h, int len, t_flags *flags)
{
	if (flags->minus && flags->width && h == 0 && !flags->pointer)
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
