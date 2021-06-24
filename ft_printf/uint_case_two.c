#include "ft_printf.h"

void	m_w_uint(unsigned int h, t_flags *flags, int len)
{
	if (flags->minus && flags->width)
	{
		ft_putnbr_uint(h, flags);
		flags->minus = 0;
		if (flags->width)
		{
			len = ft_lennbr_uint(h);
			flags->width -= len;
			ft_flag_width(flags->width, 0, flags->zero, flags);
		}
		flags->width = 0;
	}
}

void	m_w_h_pointer_uint(unsigned int h, t_flags *flags)
{
	if (flags->minus && flags->width && h == 0 && !flags->pointer)
	{
		ft_putnbr_uint(h, flags);
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
	}
	else if (flags->width && !flags->point && h == 0 && flags->minus)
	{
		if (flags->width)
			flags->width++;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
	}
}

void	point_m_uint(unsigned int h, t_flags *flags, int len)
{
	if (flags->point)
	{
		if (flags->point >= len)
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
		ft_putnbr_uint(h, flags);
	}
}

int	w_p_uint(unsigned int h, t_flags *flags, int len)
{
	if (flags->width < len && flags->point < len)
	{
		ft_putnbr_uint(h, flags);
		return (flags->len_word);
	}
	if (flags->point < flags->width && flags->point > 0)
		flags->zero = 0;
	if (flags->width)
	{
		if (flags->point < len)
		{
			flags->width -= len;
			flags->point = 0;
		}
		if (flags->point > 0 && h < 0)
			flags->point++;
		flags->width -= flags->point;
		ft_flag_width(flags->width, 0, flags->zero, flags);
		h = ft_putnbr_minus(h, flags);
	}
	if (flags->point)
		point_m_uint(h, flags, len);
	else
		ft_putnbr_uint(h, flags);
	return (flags->len_word);
}

int	m_w_p_uint(unsigned int h, t_flags *flags, int len)
{
	if (flags->minus && flags->width && flags->point)
	{
		if (h < 0)
		{
			ft_putchar_fd('-', flags);
			h *= -1;
			len--;
			flags->width--;
		}
		if (flags->point)
			point_m_uint(h, flags, len);
		if (flags->width)
		{
			flags->width -= len;
			ft_flag_width(flags->width, 0, flags->zero, flags);
		}
		return (flags->len_word);
	}
	return (flags->len_word);
}
