#include "ft_printf.h"

void	point_minus_X(unsigned int h, t_flags *flags, int len)
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
		hexa_dis_sys_X(h, flags);
	}
}

void	minus_width_h_X(unsigned int h, t_flags *flags, int len)
{
	if (h == 0)
		ft_putstr_fd("0", flags);
	else
		hexa_dis_sys_X(h, flags);
	flags->minus = 0;
	if (flags->width)
	{
		flags->width -= len;
		ft_flag_width(flags->width, 0, flags->zero, flags);
	}
	flags->width = 0;
}

void	width_point_h_X(unsigned int h, t_flags *flags, int len)
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
			hexa_dis_sys_X(h, flags);
		}
		flags->width = 0;
		flags->point = 0;
	}
}

void	minus_width_h_pointer_X(unsigned int h, t_flags *flags, int len)
{
	if (flags->minus && flags->width && h == 0 && !flags->pointer)
	{
		if (h == 0)
			ft_putstr_fd("0", flags);
		else
			hexa_dis_sys_X(h, flags);
		flags->minus = 0;
		if (flags->width)
		{
			flags->width -= len;
			ft_flag_width(flags->width, 0, flags->zero, flags);
		}
		flags->width = 0;
	}
}

int	minus_width_point_X(unsigned int h, t_flags *flags, int len)
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
		hexa_dis_sys_X(h, flags);
	}
	if (flags->width)
	{
		flags->width -= len;
		ft_flag_width(flags->width, 0, flags->zero, flags);
	}
	return (flags->len_word);
}
