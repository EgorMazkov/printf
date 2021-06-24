#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, t_flags *flags)
{
	int		i;

	i = 0;
	while (s[i] != 0)
	{
		ft_putchar_fd(s[i], flags);
		i++;
	}
}

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	buff;

	i = 0;
	length = ft_strlen_two(str);
	while (length - 1 > i)
	{
		buff = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buff;
		length--;
		i++;
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;
	int		len;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	dest = malloc(sizeof(*s1) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen_two(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
