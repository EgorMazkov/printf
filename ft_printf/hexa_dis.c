#include "ft_printf.h"

void	hexa_dis_sys(unsigned int n, t_flags *flags)
{
	int		ost;
	char	*dext;

	dext = "0123456789abcdef";
	if (n >= 16)
		hexa_dis_sys(n / 16, flags);
	ost = n % 16;
	write(1, &dext[ost], 1);
	flags->len_word++;
}

int	hexa_dis(unsigned int n)
{
	int	ost;
	int	len;

	len = 0;
	if (n == 0)
	{
		len = 1;
		return (len);
	}
	while (n >= 16)
	{
		n = (n / 16);
		len++;
	}
	ost = n % 16;
	if (n % 16)
		len++;
	return (len);
}
