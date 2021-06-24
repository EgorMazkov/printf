#include "ft_printf.h"

static	void	flag_parser(const char *save, int i, \
t_flags *flags, va_list args)
{
	if (save[i] == '*')
	{
		ft_flag_digit_width(va_arg(args, int), flags);
		if (flags->width < 0)
			ft_flag_width_minus(flags->width, \
			flags->minus, flags->zero, flags);
	}
	if (save[i] == '-')
		*flags = ft_flag_minus(*flags);
	else if (ft_isdigit(save[i]))
		*flags = ft_flag_digit(save[i], *flags);
}

int	ft_flag_parse(const char *save, int i, t_flags *flags, va_list args)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !ft_type(save[i]) \
		&& !ft_proverka_flags(save[i]))
			break ;
		if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
		{
			flags->zero = 1;
			i++;
		}
		if (save[i] == '.')
		{
			flags->pointer++;
			i = ft_flag_null(save, i, flags, args);
		}
		flag_parser(save, i, flags, args);
		if (ft_type(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}
