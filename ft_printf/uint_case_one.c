#include "ft_printf.h"

void	w_uint(unsigned int h, t_flags *flags, int len)
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
		ft_putnbr_uint(h, flags);
	}
}

int	w_h_pointer_uint(unsigned int h, t_flags *flags, int len)
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
		ft_putnbr_uint(h, flags);
	}
	return (flags->len_word);
}

void	point_uint(unsigned int h, t_flags *flags, int len)
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
	ft_putnbr_uint(h, flags);
}

void	minus_uint(unsigned int h, t_flags *flags, int len)
{
	if (flags->minus)
	{
		ft_putnbr_uint(h, flags);
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

void	p_m_uint(unsigned int h, t_flags *flags, int len)
{
	if (flags->point && flags->minus)
	{
		flags->minus = 0;
		if (h < 0)
		{
			ft_putnbr_minus(h, flags);
			h *= -1;
			len -= 1;
		}
		flags->point -= len;
		while (flags->point != 0)
		{
			ft_putchar_fd('0', flags);
			flags->point--;
		}
		ft_putnbr_uint(h, flags);
	}
}
