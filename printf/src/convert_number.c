/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_number.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/03 16:28:04 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/06 00:41:26 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*convert_int(t_flags flags, int nb)
{
	int		nb_size;
	int		res_size;
	char	*res;

	nb_size = number_size(nb, get_base(flags.type), flags);
	res_size = nb_size;
	if (flags.precision == 1 && flags.max_width >= nb_size)
	{
		res_size = flags.max_width;
		if (nb < 0)
			res_size++;
	}
	res = strloc(res_size + 1);
	if (res == NULL)
		return (NULL);
	res = number_to_str(flags, nb, res_size, res);
	return (res);
}

int		ul_size(unsigned long n, int base, t_flags flags)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n > 0)
	{
		n = n / base;
		size++;
	}
	if (flags.padding == '0' && flags.min_width > size)
		return (flags.min_width);
	return (size);
}

char	*convert_unsigned(t_flags flags, unsigned long nb)
{
	int		nb_size;
	int		res_size;
	char	*str;

	nb_size = unsigned_size(nb, get_base(flags.type), flags);
	
