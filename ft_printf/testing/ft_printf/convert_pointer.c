/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_pointer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 12:37:37 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/10 00:40:10 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ul_size(unsigned long nb, int base, t_flags flags)
{
	int		size;

	size = 0;
	if (nb == 0)
		size++;
	while (nb > 0)
	{
		nb = nb / base;
		size++;
	}
	if (flags.padding == '0' && flags.min_width > size)
		return (flags.min_width);
	return (size);
}

char	*assign_ulong(t_flags flags, unsigned long nb, int len, char *str)
{
	int						base;

	base = get_base(flags.type);
	padding_zero(str, len);
	str[len + 1] = '\0';
	if (nb == 0 && flags.precision == 0 && flags.max_width >= 0)
		str[0] = '0';
	while (nb > 0 && len >= 0)
	{
		str[len] = (nb % base) + get_addchar(flags.type, nb % base);
		nb = nb / base;
		len--;
	}
	return (str);
}

char	*convert_ulong(t_flags flags, unsigned long nb)
{
	int		nb_size;
	int		res_size;
	char	*res;

	nb_size = ul_size(nb, get_base(flags.type), flags);
	res_size = nb_size;
	if (flags.precision == 1 && flags.max_width >= nb_size)
		res_size = flags.max_width;
	if (flags.precision == 1 && flags.max_width >= nb_size && nb == 0)
		res_size++;
	res = strloc(res_size + 1);
	if (res == NULL)
		return (NULL);
	res = assign_ulong(flags, nb, res_size - 1, res);
	return (res);
}
