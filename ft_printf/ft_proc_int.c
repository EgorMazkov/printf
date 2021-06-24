#include "ft_printf.h"

int	ft_lennbr(long i)
{
	int	p;

	p = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		p++;
	}
	while (i)
	{
		i /= 10;
		p++;
	}
	return (p);
}

int	ft_putnbr_minus(long n, t_flags *flags)
{
	if (n < 0)
	{
		write(1, "-", 1);
		flags->len_word++;
		n *= -1;
	}
	return (n);
}

void	ft_putnbr_fd(long n, t_flags *flags)
{
	char	tmp;

	if (n < 0)
	{
		write(1, "-", 1);
		flags->len_word++;
		n *= -1;
	}
	if (n == -2147483648)
		n *= -1;
	if (n >= 10)
		ft_putnbr_fd(n / 10, flags);
	tmp = (n % 10) + '0';
	write(1, &tmp, 1);
	flags->len_word++;
}

static	void	p_m_m_w_p_d(long h, t_flags *flags, int len)
{
	if (flags->point && flags->minus)
		p_m_d(h, flags, len);
	else if (flags->minus)
		minus_d(h, flags, len);
	else if (flags->width && flags->point < 0)
		w_p_d(h, flags, len);
}

int	ft_treat_int(long h, t_flags *flags, int len)
{
	len = ft_lennbr(h);
	if (flags->minus && flags->width && flags->point)
		m_w_p_d(h, flags, len);
	else if ((flags->minus && flags->width && h == 0 && !flags->pointer) || \
	(flags->width && !flags->point && h == 0 && flags->minus) || \
	(flags->minus && flags->width))
		m_w_h_pointer(h, flags, len);
	else if ((flags->point && flags->minus) || flags->minus || \
	(flags->width && flags->point < 0))
		p_m_m_w_p_d(h, flags, len);
	else if (flags->width && flags->point)
		w_p_d_i(h, flags, len);
	else if (flags->pointer && h == 0 && !flags->width && !flags->point)
		return (flags->len_word);
	else if (flags->point)
		point_d(h, flags, len);
	else if (flags->width && h == 0 && flags->pointer)
		w_h_pointer(h, flags, len);
	else if (flags->width)
		width_d(h, flags, len);
	else if (flags->width && !flags->point && h == 0)
		w_p_h_d(h, flags);
	else
		ft_putnbr_fd(h, flags);
	return (flags->len_word);
}
