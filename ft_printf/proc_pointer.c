#include "ft_printf.h"

char	*ft_count(unsigned long long nb)
{
	char	*abc;
	int		i;

	i = 0;
	abc = malloc(50);
	while (nb > 0)
	{
		if (nb % 16 > 9)
		{
			abc[i] = (nb % 16 - 10) + 'a';
		}
		else
			abc[i] = nb % 16 + '0';
		nb = nb / 16;
		i++;
	}
	abc[i] = 0;
	abc = ft_strrev(abc);
	return (abc);
}

int	ft_chet(unsigned long long nb)
{
	char	*abc;
	int		i;

	i = 0;
	abc = malloc(50);
	while (nb > 0)
	{
		if (nb % 16 > 9)
		{
			abc[i] = (nb % 16 - 10) + 'a';
			i++;
		}
		else
		{
			abc[i] = nb % 16 + '0';
			i++;
		}
		nb = nb / 16;
	}
	abc[i] = 0;
	return (i);
}

void	width_pointer_h(unsigned long long h, int len, t_flags *flags)
{
	if (flags->width && flags->pointer && h == 0)
	{
		if (flags->width)
		{
			flags->width -= len;
			ft_flag_width(flags->width, 0, 0, flags);
		}
		ft_putstr_fd("0x", flags);
	}
}

void	minus_width_h_pointer_pnt(unsigned long long h, int len, t_flags *flags)
{
	if (flags->minus && flags->width && h == 0 && flags->pointer)
	{
		flags->minus = 0;
		ft_putstr_fd("0x", flags);
		flags->width -= len;
		ft_flag_width(flags->width, flags->minus, flags->zero, flags);
	}
}

void	ft_count_putstr(char *dest, unsigned long long h, t_flags *flags)
{
	ft_putstr_fd("0x", flags);
	dest = ft_count(h);
	ft_putstr_fd(dest, flags);
}
