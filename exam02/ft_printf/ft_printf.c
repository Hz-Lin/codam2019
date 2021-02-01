#include <unistd.h>
#include <stdarg.h>

static int	ft_nbrlen(long n, int base)
{
	int	i = 1;

	while (n >= base)
	{
		n /= base;
		i++;
	}
	return (i);
}

static void	ft_putnbr(long nbr, int base, char *base_str)
{
	if (nbr >= base)
		ft_putnbr(nbr/base, base, base_str);
	write(1, &base_str[nbr % base], 1);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	char		*str;
	char		*s;
	long		nbr;
	int			neg;
	int			len;
	int			width;
	int			prec;
	int			spaces;
	int			zeros;
	int			count;

	va_start(args, format);
	str = (char*)format;
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			neg = 0;
			len = 0;
			width = 0;
			prec = -1;
			spaces = 0;
			zeros = 0;
			while (*str >= '0' && *str <= '9')
			{
				width = width * 10 + (*str - 48);
				str++;
			}
			if (*str == '.')
			{
				prec = 0;
				str++;
				while (*str >= '0' && *str <= '9')
				{
					prec = prec * 10 + (*str - 48);
					str++;
				}
			}
			if (*str == 's')
			{
				s = va_arg(args, char*);
				if (!s)
					s = "(null)";
				while (s[len])
					len++;
			}
			if (*str == 'd')
			{
				nbr = va_arg(args, int);
				if (nbr < 0)
				{
					nbr = -nbr;
					neg = 1;
				}
				len = ft_nbrlen(nbr, 10) + neg;
			}
			if (*str == 'x')
			{
				nbr = va_arg(args, unsigned);
				len = ft_nbrlen(nbr, 16);
			}
			if (prec >= len && *str != 's')
				zeros = prec - len + neg;
			else if (prec > -1 && prec < len && *str == 's')
				len = prec;
			else if (prec == 0 && (*str == 's' || nbr == 0))
				len = 0;
			spaces = width - zeros - len;
			while (spaces-- > 0)
				count += write(1, " ", 1);
			if (neg == 1)
				write(1, "-", 1);
			while (zeros-- > 0)
				count += write(1, "0", 1);
			if (*str == 's')
				write(1, s, len);
			else if (*str == 'd' && len > 0)
				ft_putnbr(nbr, 10, "0123456789");
			else if (*str == 'x' && len > 0)
				ft_putnbr(nbr, 16, "0123456789abcdef");
			count += len;
		}
		else
		{
			count += write(1, str, 1);
		}
		str++;
	}
	va_end(args);
	return (count);
}
