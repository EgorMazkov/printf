#include "ft_printf.h"

void	ft_proc_pnt_two(unsigned long long h, int len, \
t_flags *flags, char *dest)
{
	if (flags->width)
		width_pnt(dest, h, len, flags);
	else if (flags->point)
		point_pnt(h, len, flags);
}

void	width_point_pnt_if(unsigned long long h, int len, \
char *dest, t_flags *flags)
{
	if (flags->width && flags->point)
	{
		width_point_pnt(len, flags);
		dest = ft_count(h);
		ft_putstr_fd(dest, flags);
	}
}

void	minus_width_pointer_pnt(unsigned long long h, t_flags *flags)
{
	if (!flags->minus && !flags->width && !flags->pointer \
	&& !flags->point && h == 0)
	{
		ft_putstr_fd("0x", flags);
		ft_putstr_fd("0", flags);
	}
}

void	nominus_nowidth_nopointer_h(t_flags *flags)
{
	ft_putstr_fd("0x", flags);
	ft_putstr_fd("0", flags);
}
