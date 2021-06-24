#include "ft_printf.h"

void	ft_cshet(char *str, t_flags *flags, int len)
{
	while (len != 0)
	{
		ft_putchar_fd(*str, flags);
		str++;
		len--;
	}
}

int	cshet_ret(char *str, t_flags *flags, int len)
{
	ft_cshet(str, flags, len);
	return (flags->len_word);
}

static	int	ft_two_str(char *str, t_flags *flags, int len)
{
	if (str == NULL && flags->width && !flags->minus && flags->point)
		str_w_m_p(str, flags, len);
	else if (str == NULL && flags->minus && flags->width && flags->point)
		str_m_w_p(str, flags, len);
	else if (flags->point && flags->pointer && !flags->width && \
	!flags->minus && !flags->zero && str == NULL)
		p_pointer_now_nom_noz_str(str, flags, len);
	else if (!flags->point && !flags->pointer && flags->width && \
	flags->minus && !flags->zero && str == NULL)
		p_pointer_w_p_m_w_str(str, flags, len);
	else if (flags->width && str == NULL && !flags->point)
		w_str_p(str, flags, len);
	else if (flags->minus && str == 0 && !flags->width && !flags->point)
		cshet_ret(str, flags, len);
	else if (flags->pointer && str == 0 && !flags->width && !flags->point)
		return (flags->len_word);
	return (flags->len_word);
}

static	int	ft_three_str(char *str, t_flags *flags, int len)
{
	if ((str == NULL && flags->width && !flags->minus && flags->point) || \
	(str == NULL && flags->minus && flags->width && flags->point) || \
	(flags->point && flags->pointer && !flags->width && \
	!flags->minus && !flags->zero && str == NULL) || \
	(!flags->point && !flags->pointer && flags->width && \
	flags->minus && !flags->zero && str == NULL) || \
	(flags->width && str == NULL && !flags->point) || \
	(flags->minus && str == 0 && !flags->width && !flags->point) || \
	(flags->pointer && str == 0 && !flags->width && !flags->point))
		ft_two_str(str, flags, len);
	len = (ft_strlen_two(str));
	if (flags->minus && flags->point && flags->width)
		m_p_w_str(str, flags, len);
	else if (flags->point && flags->width)
		p_w_str(str, flags, len);
	else if ((flags->point) || (flags->pointer && !flags->width && \
	!flags->point) || (flags->minus && flags->width))
		p_pointer_w_p_m_w_str(str, flags, len);
	else if ((flags->pointer && flags->width) || flags->width)
		p_w_w_str(str, flags, len);
	else if (flags->pointer && !flags->width && !flags->point)
		return (flags->len_word);
	else
		ft_cshet(str, flags, len);
	return (flags->len_word);
}

int	ft_treat_string(char *str, t_flags *flags)
{
	int	len;

	len = 6;
	if (str == NULL)
		str = "(null)";
	if (str == NULL && !flags->width && !flags->minus && !flags->pointer)
		cshet_ret(str, flags, len);
	else if (!flags->point && str == NULL && \
	flags->width && !flags->minus && flags->pointer)
	{
		if (flags->width)
			ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		return (flags->len_word);
	}
	else if (flags->width && flags->pointer && !flags->point && flags->minus)
	{
		flags->width++;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		return (flags->len_word);
	}
	ft_three_str(str, flags, len);
	return (flags->len_word);
}
