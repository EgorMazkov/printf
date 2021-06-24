#include "ft_printf.h"

void	point_d_i(long h, t_flags *flags, int len)
{
	if (flags->point)
	{
		if (flags->point > len)
			flags->point -= len;
		else
			flags->point = 0;
		if (flags->point != 0)
			flags->width -= flags->point;
		while (flags->point != 0)
		{
			ft_putchar_fd('0', flags);
			flags->point--;
		}
		ft_putnbr_fd(h, flags);
	}
}

void	w_p_h_d(long h, t_flags *flags)
{
	if (flags->width && !flags->point && h == 0)
	{
		if (flags->width)
			ft_flag_width(flags->width, flags->minus, flags->zero, flags);
	}
}

void	width_d(long h, t_flags *flags, int len)
{
	if (flags->width)
	{
		if (h < 0 && flags->zero)
		{
			ft_putnbr_minus(h, flags);
			h *= -1;
		}
		flags->width -= len;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		ft_putnbr_fd(h, flags);
	}
}

int	w_h_pointer(long h, t_flags *flags, int len)
{
	if (flags->width && h == 0 && flags->pointer)
	{
		if (h < 0 && flags->zero)
			h = ft_putnbr_minus(h, flags);
		if (h != 0)
			flags->width -= len;
		ft_flag_width(flags->width, 0, flags->zero, flags);
		if (h == 0)
			return (flags->len_word);
		ft_putnbr_fd(h, flags);
	}
	return (flags->len_word);
}

void	point_d(long h, t_flags *flags, int len)
{
	if (flags->point)
	{
		if (h < 0)
		{
			h = ft_putnbr_minus(h, flags);
			len--;
		}
		if (flags->point > len)
		{
			flags->point -= len;
		}
		else
			flags->point = 0;
		while (flags->point != 0)
		{
			ft_putchar_fd('0', flags);
			flags->point--;
		}
		ft_putnbr_fd(h, flags);
	}
}
