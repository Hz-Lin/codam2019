/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_number_utilities.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/03 16:28:04 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/06 00:24:35 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return (10);
	else if (type == 'x' || type == 'X' || type == 'p')
		return (16);
	else
		return (-1);
}

int		number_size(long long nb, int base, t_flags flags)
{
	int					size;
	unsigned long long	n;

	size = 0;
	if (nb < 0)
	{
		n = -1 * nb;
		size++;
	}
	else
	{
		n = nb;
	}
	while (n > 0)
	{
		n = n / base;
		size++;
	}
	if (flags.padding == '0' && flags.min_width > size)
		return (flags.min_width);
	return (size);
}

void	padding_zero(char *str, int len)
{
	int	i;

	i = 0;
	while (i < (len - 1))
	{
		str[i] = '0';
		i++;
	}
	str[i] = 0;
}

char	get_addchar(char type, int num)
{
	if (num > 10 && num <= 16)
	{
		if (type == 'x' || type == 'p')
			return ('a' - 10);
		if (type == 'X')
			return ('A' - 10);
	}
	return ('0');
}

char	*number_to_str(t_flags flags, long long nb, int len, char *str)
{
	unsigned long long		n;
	int						base;

	base = get_base(flags.type);
	n = nb;
	padding_zero(str, len);
	if (nb == 0 && flags.precision == 0 && flags.max_width >= 0) //check why
		str[0] = '0';
	while (n > 0 && len > 0)
	{
		str[len - 1] = (n % base) + get_addchar(flags.type, n % base);
		n = n / base;
		len--;
	}
	return (str);
}
