#include "ft_printf.h"

void	point_pnt(unsigned long long h, int len, t_flags *flags)
{
	if (flags->point)
	{
		ft_putstr_fd("0x", flags);
		if (h == 0)
			len = 0;
		if (flags->point > len)
			flags->point -= len;
		while (flags->point)
		{
			ft_putchar_fd('0', flags);
			flags->point--;
		}
	}
}

void	width_h_pnt(unsigned long long h, int len, t_flags *flags)
{
	if (flags->width && h == 0)
	{
		len++;
		flags->width -= len;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
		ft_putstr_fd("0x", flags);
		ft_putstr_fd("0", flags);
	}
}

void	width_point_pnt( int len, t_flags *flags)
{
	if (flags->width && flags->point)
	{
		if (flags->point <= flags->width)
		{
			if (flags->width)
			{
				flags->width -= len;
				ft_flag_width(flags->width, flags->minus, flags->zero, flags);
			}
		}
		ft_putstr_fd("0x", flags);
		if (flags->point)
		{
			len -= 2;
			if (flags->point > len)
				flags->point -= len;
			else
				flags->point = 0;
			while (flags->point != 0)
			{
				ft_putchar_fd('0', flags);
				flags->point--;
			}
		}
	}
}

static	void	minus_width_h_pnt(unsigned long long h, int len, t_flags *flags)
{
	if (flags->minus && flags->width && h == 0)
	{
		len++;
		flags->minus = 0;
		ft_putstr_fd("0x", flags);
		ft_putstr_fd("0", flags);
		flags->width -= len;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
	}
}

int	ft_proc_pnt(unsigned long long h, t_flags *flags, int len)
{
	char	*dest;

	dest = NULL;
	len = ft_chet(h) + 2;
	if (!flags->minus && !flags->width && !flags->pointer && h == 0)
		nominus_nowidth_nopointer_h(flags);
	else if (flags->minus && flags->width && h == 0 && flags->pointer)
		minus_width_h_pointer_pnt(h, len, flags);
	else if (flags->minus && flags->width && h == 0)
		minus_width_h_pnt(h, len, flags);
	else if (flags->width && flags->pointer && h == 0)
		width_pointer_h(h, len, flags);
	else if (h == 0 && flags->pointer && !flags->point)
		ft_putstr_fd("0x", flags);
	else if (flags->width && h == 0)
		width_h_pnt(h, len, flags);
	else if (flags->minus && flags->width)
		minus_width_pnt(dest, h, len, flags);
	else if (flags->width && flags->point)
		width_point_pnt_if(h, len, dest, flags);
	else if (flags->width || flags->point)
		ft_proc_pnt_two(h, len, flags, dest);
	else
		ft_count_putstr(dest, h, flags);
	return (flags->len_word);
}
