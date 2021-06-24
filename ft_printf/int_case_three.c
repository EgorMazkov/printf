#include "ft_printf.h"

int	m_w_p_d(long h, t_flags *flags, int len)
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
			point_d_i(h, flags, len);
		if (flags->width)
		{
			flags->width -= len;
			ft_flag_width(flags->width, 0, flags->zero, flags);
		}
		return (flags->len_word);
	}
	return (flags->len_word);
}
