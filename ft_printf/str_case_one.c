#include "ft_printf.h"

void	p_w_w_str(char *str, t_flags *flags, int len)
{
	if (flags->pointer && flags->width)
	{
		if (flags->point < len)
			len = flags->point;
		flags->width -= len;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
	}
	else if (flags->width)
	{
		flags->width -= len;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		ft_cshet(str, flags, len);
	}
}

int	p_pointer_w_p_m_w_str(char *str, t_flags *flags, int len)
{
	if (flags->point)
	{
		if (flags->point < 0 && !flags->width)
			flags->point = len;
		else if (flags->point < 0)
			flags->point = flags->width;
		else if (flags->point < len)
			len = flags->point;
		ft_cshet(str, flags, len);
	}
	else if (flags->pointer && !flags->width && !flags->point)
		return (flags->len_word);
	else if (flags->minus && flags->width)
	{
		flags->width -= len;
		flags->width++;
		ft_cshet(str, flags, len);
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
	}
	return (flags->len_word);
}

void	p_w_str(char *str, t_flags *flags, int len)
{
	if (flags->point && flags->width)
	{
		if (flags->point)
		{
			if (flags->point < 0)
				flags->point = flags->width;
			if (flags->point < len)
				len = flags->point;
		}
		if (flags->width)
		{
			flags->width -= len;
			ft_flag_width(flags->width, flags->minus, flags->zero, flags);
			ft_cshet(str, flags, len);
		}
	}
}

void	m_p_w_str(char *str, t_flags *flags, int len)
{
	if (flags->minus && flags->point && flags->width)
	{
		flags->minus = 0;
		if (flags->point)
		{
			if (flags->point < 0)
				flags->point = flags->width;
			if (flags->point < len)
				len = flags->point;
		}
		ft_cshet(str, flags, len);
		if (flags->width)
		{
			flags->width -= len;
			ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		}
	}
}

int	str_m_w_p(char *str, t_flags *flags, int len)
{
	if (str == NULL && flags->minus && flags->width && flags->point)
	{
		p_l_str(flags, len);
		if (flags->point == 0)
		{
			flags->width++;
			ft_flag_width(flags->width, flags->minus, flags->zero, flags);
			return (flags->len_word);
		}
		if (flags->minus)
		{
			flags->minus = 0;
			ft_cshet(str, flags, len);
		}
		else
			ft_cshet(str, flags, len);
		if (flags->width)
		{
			flags->width -= len;
			ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		}
		return (flags->len_word);
	}
	return (flags->len_word);
}
