#include "ft_printf.h"

void	width_X(unsigned int h, t_flags *flags, int len)
{
	if (flags->width)
	{
		flags->width -= len;
		ft_flag_width(flags->width, 0, flags->zero, flags);
		hexa_dis_sys_X(h, flags);
	}
	else if (flags->point)
	{
		if (flags->point > len)
		{
			flags->point -= len;
			while (flags->point != 0)
			{
				ft_putchar_fd('0', flags);
				flags->point--;
			}
			hexa_dis_sys_X(h, flags);
		}
		else
			hexa_dis_sys_X(h, flags);
	}
	else if (flags->minus)
		minus_X(h, flags, len);
}

void	h_width_pointer(unsigned int h, t_flags *flags)
{
	if (h == 0 && flags->width && flags->pointer)
	{
		ft_flag_width(flags->width, 0, flags->zero, flags);
		flags->width = 0;
	}
}

void	minus_X(unsigned int h, t_flags *flags, int len)
{
	if (flags->minus)
	{
		hexa_dis_sys_X(h, flags);
		if (flags->width)
		{
			flags->width -= flags->point;
			ft_flag_width(flags->width, 0, flags->zero, flags);
			if (flags->point)
			{
				flags->point -= len;
				while (flags->point != 0)
				{
					ft_putchar_fd('0', flags);
					flags->point--;
				}
			}
		}
	}
}
