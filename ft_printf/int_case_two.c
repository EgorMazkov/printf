#include "ft_printf.h"

int	w_p_d_i(long h, t_flags *flags, int len)
{
	if (flags->width < len && flags->point < len)
	{
		ft_putnbr_fd(h, flags);
		return (flags->len_word);
	}
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
		ft_flag_width(flags->width, 0, 0, flags);
		h = ft_putnbr_minus(h, flags);
	}
	if (flags->point)
		point_d_i(h, flags, len);
	else
		ft_putnbr_fd(h, flags);
	return (flags->len_word);
}

int	w_p_d(long h, t_flags *flags, int len)
{
	if (flags->width < len && flags->point < len)
	{
		ft_putnbr_fd(h, flags);
		return (flags->len_word);
	}
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
		point_d_i(h, flags, len);
	else
		ft_putnbr_fd(h, flags);
	return (flags->len_word);
}

void	minus_d(long h, t_flags *flags, int len)
{
	if (flags->minus)
	{
		ft_putnbr_fd(h, flags);
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

void	p_m_d(long h, t_flags *flags, int len)
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
		if (flags->point > len)
			flags->point -= len;
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

void	m_w_h_pointer(long h, t_flags *flags, int len)
{
	if (flags->minus && flags->width && h == 0 && !flags->pointer)
	{
		ft_putnbr_fd(h, flags);
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
	}
	else if (flags->width && !flags->point && h == 0 && flags->minus)
	{
		if (flags->width)
			flags->width++;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
	}
	else if (flags->minus && flags->width)
	{
		ft_putnbr_fd(h, flags);
		flags->minus = 0;
		if (flags->width)
		{
			len = ft_lennbr(h);
			flags->width -= len;
			ft_flag_width(flags->width, 0, flags->zero, flags);
		}
		flags->width = 0;
	}
}
