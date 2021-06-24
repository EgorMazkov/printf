#include "ft_printf.h"

void	ft_putchar_fd(char c, t_flags *flags)
{
	write (1, &c, 1);
	flags->len_word++;
}
