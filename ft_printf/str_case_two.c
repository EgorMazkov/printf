#include "ft_printf.h"

void	p_l_str(t_flags *flags, int len)
{
	if (flags->point < len)
		len = flags->point;
}

int	p_pointer_w_m_z_str(char *str, t_flags *flags, int len)
{
	if (!flags->point && !flags->pointer && flags->width && flags->minus && \
	!flags->zero && str == NULL)
	{
		ft_cshet(str, flags, len);
		if (flags->width)
		{
			flags->width -= len;
			flags->width++;
			ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		}
		return (flags->len_word);
	}
	return (flags->len_word);
}

void	str_w_m_p(char *str, t_flags *flags, int len)
{
	if (str == NULL && flags->width && !flags->minus && flags->point)
	{
		p_l_str(flags, len);
		if (flags->width)
		{
			flags->width -= len;
			ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		}
		cshet_ret(str, flags, len);
	}
}

void	w_str_p(char *str, t_flags *flags, int len)
{
	if (flags->width && str == NULL && !flags->point)
	{
		flags->width -= len;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		cshet_ret(str, flags, len);
	}
}

void	p_pointer_now_nom_noz_str(char *str, t_flags *flags, int len)
{
	if (flags->point && flags->pointer && !flags->width && \
	!flags->minus && !flags->zero && str == NULL)
	{
		p_l_str(flags, len);
		cshet_ret(str, flags, len);
	}
}
