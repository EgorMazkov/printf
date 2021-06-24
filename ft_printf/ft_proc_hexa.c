#include "ft_printf.h"

int	minus(unsigned int h, int len, t_flags *flags)
{
	if (flags->minus)
	{
		hexa_dis_sys(h, flags);
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
	return (flags->len_word);
}

static	void	width_pointer(unsigned int h, t_flags *flags)
{
	if (h == 0 && flags->width && flags->pointer)
	{
		ft_flag_width(flags->width, 0, flags->zero, flags);
		flags->width = 0;
	}
}

int	ft_treat_hexa(unsigned int h, t_flags *flags, int len)
{
	len = hexa_dis(h);
	if (!flags->width && !flags->point && !flags->minus && h != 0)
		hexa_dis_sys(h, flags);
	else if (flags->minus && flags->width && flags->point)
		minus_width_point(h, len, flags);
	else if (flags->minus && flags->width && h != 0)
		minus_width_h(h, len, flags);
	else if (flags->width && flags->point && h == 0)
		width_point_h(h, len, flags);
	else if (flags->minus && flags->width && h == 0 && !flags->pointer)
		minus_width_h_pointer(h, len, flags);
	else if (h == 0 && flags->width && flags->pointer)
		width_pointer(h, flags);
	else if (flags->minus)
		minus(h, len, flags);
	else if (flags->width && flags->point)
		width_point(h, len, flags);
	else if (flags->width)
		width(h, len, flags);
	else if (flags->point)
		point(h, len, flags);
	else if (h == 0 && !flags->width && !flags->point && \
	!flags->minus && !flags->pointer)
		ft_putchar_fd('0', flags);
	return (flags->len_word);
}
