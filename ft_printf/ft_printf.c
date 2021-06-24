#include "ft_printf.h"

void	zeroing(t_flags *flags)
{
	flags->minus = 0;
	flags->type = 0;
	flags->width = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->point = 0;
	flags->len_word = 0;
	flags->pointer = 0;
}

void	zeroing_without_len_word(t_flags *flags)
{
	flags->minus = 0;
	flags->type = 0;
	flags->width = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->point = 0;
	flags->pointer = 0;
}

int	ft_treat_save(const char *save, va_list args, t_flags *flags)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	zeroing(flags);
	while (save[i])
	{
		if (!save[i])
			break ;
		else if (save[i] == '%')
		{
			zeroing_without_len_word(flags);
			i = ft_flag_parse(save, ++i, flags, args);
			if (ft_type(save[i]))
				flags->len_word = ft_processor((char)flags->type, flags, args);
			else if (save[i])
				ft_putchar_fd(save[i], flags);
		}
		else if (save[i] != '%')
			ft_putchar_fd(save[i], flags);
		i++;
	}
	return (flags->len_word);
}

int	ft_printf(const char *input, ...)
{
	const char	*save;
	va_list		args;
	int			count;
	t_flags		flags;

	save = ft_strdup(input);
	count = 0;
	va_start(args, input);
	count = ft_treat_save(save, args, &flags);
	va_end(args);
	free((char *)save);
	return (flags.len_word);
}
