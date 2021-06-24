#include "ft_printf.h"

void	hexa_dis_sys_X(unsigned int n, t_flags *flags)
{
	int		ost;
	char	*dext;

	dext = "0123456789ABCDEF";
	if (n >= 16)
		hexa_dis_sys_X(n / 16, flags);
	ost = n % 16;
	write(1, &dext[ost], 1);
	flags->len_word++;
}

static	void	width_point_X(unsigned int h, t_flags *flags, int len)
{
	if (flags->width && flags->point)
	{
		if (flags->width)
		{
			if (flags->point < len)
			{
				flags->width -= len;
				flags->point = 0;
			}
			flags->width -= flags->point;
			ft_flag_width(flags->width, 0, 0, flags);
		}
		if (flags->point)
		{
			flags->point -= len;
			while (flags->point != 0)
			{
				ft_putchar_fd('0', flags);
				flags->point--;
			}
		}
		hexa_dis_sys_X(h, flags);
	}
}

int	ft_treat_hexa_X(unsigned int h, t_flags *flags)
{
	int	len;

	len = hexa_dis(h);
	if (!flags->width && !flags->point && !flags->minus && h != 0)
		hexa_dis_sys_X(h, flags);
	else if (flags->minus && flags->width && flags->point)
		minus_width_point_X(h, flags, len);
	else if (flags->minus && flags->width && h != 0)
		minus_width_h_X(h, flags, len);
	else if (flags->width && flags->point && h == 0)
		width_point_h_X(h, flags, len);
	else if (flags->minus && flags->width && h == 0 && !flags->pointer)
		minus_width_h_pointer_X(h, flags, len);
	else if (h == 0 && flags->width && flags->pointer)
		h_width_pointer(h, flags);
	else if (flags->point && flags->minus)
		point_minus_X(h, flags, len);
	else if (flags->width && flags->point)
		width_point_X(h, flags, len);
	else if (flags->width || flags->point || flags->minus)
		width_X(h, flags, len);
	else if (h == 0 && !flags->width && \
	!flags->point && !flags->minus && !flags->pointer)
		ft_putchar_fd('0', flags);
	return (flags->len_word);
}
