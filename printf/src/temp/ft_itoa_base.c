#include "../libft/libft.h"

static int	cal_len(long n, int base)
{
	int			len;

	len = 0;
	while (n != 0)
	{
		n = n / base;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

char	ft_itoa_base(int n, int base)
{
	char	*res;
	char	*intchar;

	intchar = "0123456789ABCDEF";
	if (base == 10)
	{
		res = ft_itoa(n);
		return (res);
	}
	else
	{
		res = ft_itoa_base_pre(int n, int base);
	}
}
