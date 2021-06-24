#include "ft_printf.h"

int	ft_flag_width(int width, int minus, int zero, t_flags *flags)
{
	int	count;

	count = 0;
	while (width - minus > 0)
	{
		if (zero)
		{
			ft_putchar_fd('0', flags);
			width--;
			count++;
		}
		else
		{
			ft_putchar_fd(' ', flags);
			width -= 1;
			count++;
		}
	}
	return (flags->len_word);
}

t_flags	ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

int	ft_flag_null(const char *save, int start, t_flags *flags, va_list args)
{
	int	i;

	i = start;
	i++;
	if (save[i] == '*')
	{
		flags->point = va_arg(args, int);
		i++;
	}
	else
	{
		if (ft_isdigit(save[i]) < 48)
		{
			flags->pointer++;
		}
		else
			flags->point = 0;
		while (ft_isdigit(save[i]))
			flags->point = (flags->point * 10) + (save[i++] - '0');
	}
	return (i);
}
