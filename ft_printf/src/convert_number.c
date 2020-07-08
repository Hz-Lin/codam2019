/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_number.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 18:11:13 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/09 00:05:51 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*convert_int(t_flags flags, int nb)
{
	int		negative;
	int		nb_size;
	int		res_size;
	char	*res;

	nb_size = number_size(nb, get_base(flags.type), flags);
	res_size = nb_size;
	negative = 0;
	if (flags.precision == 1 && flags.max_width >= nb_size)
	{
		res_size = flags.max_width;
		if (nb < 0)
		{
			res_size++;
			nb = -1 * nb;
			negative = 1;
		}
	}
	res = strloc(res_size + 1);
	if (res == NULL)
		return (NULL);
	res = assign_int(flags, nb, res_size, res);
	if (negative == 1)
		res[0] = '-';
	return (res);
}

char	*convert_unsigned(t_flags flags, unsigned int nb)
{
	int		nb_size;
	int		res_size;
	char	*res;

	nb_size = number_size(nb, get_base(flags.type), flags);
	res_size = nb_size;
	if (flags.precision == 1 && flags.max_width >= nb_size)
	{
		res_size = flags.max_width;
		if (nb == 0)
			res_size++;
	}
	res = strloc(res_size + 1);
	if (res == NULL)
		return (NULL);
	res = assign_int(flags, nb, res_size, res);
	return (res);
}
