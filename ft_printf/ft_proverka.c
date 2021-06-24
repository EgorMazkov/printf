#include "ft_printf.h"

int	ft_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') \
	|| (c == 'i') || (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_proverka_flags(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int	ft_processor(int c, t_flags *flags, va_list args)
{
	int	len;

	len = 0;
	if (c == 'x')
		len += ft_treat_hexa(va_arg(args, int), flags, len);
	else if (c == 'X')
		len += ft_treat_hexa_X(va_arg(args, int), flags);
	else if (c == 'c')
		len += ft_treat_char(va_arg(args, int), flags);
	else if (c == 'i' || c == 'd')
		len += ft_treat_int(va_arg(args, int), flags, len);
	else if (c == 'p')
		len += ft_proc_pnt(va_arg(args, long), flags, len);
	else if (c == 'u')
		len += ft_treat_uint(va_arg(args, unsigned int), flags, len);
	else if (c == 's')
		len += ft_treat_string(va_arg(args, char *), flags);
	else if (c == '%')
		len += ft_treat_percent(c, flags);
	return (flags->len_word);
}
