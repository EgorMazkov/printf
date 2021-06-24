#include "ft_printf.h"

int	ft_lennbr_uint(unsigned int i)
{
	unsigned int	p;

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

int	ft_putnbr_minus_uint(unsigned int n, t_flags *flags)
{
	if (n < 0)
	{
		write(1, "-", 1);
		flags->len_word++;
		n *= -1;
	}
	return (n);
}

void	ft_putnbr_uint(unsigned int n, t_flags *flags)
{
	char	tmp;

	if (n < 0)
	{
		write(1, "-", 1);
		flags->len_word++;
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_uint(n / 10, flags);
	tmp = (n % 10) + '0';
	write(1, &tmp, 1);
	flags->len_word++;
}

static	void	m_w_p_m_m_uint(unsigned int h, t_flags *flags, int len)
{
	if (flags->minus && flags->width)
		m_w_uint(h, flags, len);
	else if (flags->point && flags->minus)
		p_m_uint(h, flags, len);
	else if (flags->minus)
		minus_uint(h, flags, len);
}

unsigned	int	ft_treat_uint(unsigned int h, t_flags *flags, int len)
{
	len = ft_lennbr_uint(h);
	if (!flags->width && !flags->point && !flags->minus && h != 0)
		ft_putnbr_uint(h, flags);
	else if (flags->minus && flags->width && flags->point)
		m_w_p_uint(h, flags, len);
	else if ((flags->minus && flags->width && h == 0 && !flags->pointer) || \
	(flags->width && !flags->point && h == 0 && flags->minus))
		m_w_h_pointer_uint(h, flags);
	else if ((flags->minus && flags->width) || (flags->point && flags->minus) || \
	flags->minus)
		m_w_p_m_m_uint(h, flags, len);
	else if (flags->width && flags->point)
		w_p_uint(h, flags, len);
	else if (flags->pointer && h == 0 && !flags->width && !flags->point)
		return (flags->len_word);
	else if (flags->point)
		point_uint(h, flags, len);
	else if (flags->width && h == 0 && flags->pointer)
		w_h_pointer_uint(h, flags, len);
	else if (flags->width)
		w_uint(h, flags, len);
	else
		ft_putnbr_uint(h, flags);
	return (flags->len_word);
}
