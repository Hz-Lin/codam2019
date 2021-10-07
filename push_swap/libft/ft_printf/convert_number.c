/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_number.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 18:11:13 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/10 00:39:58 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_int(t_flags flags, int nb)
{
	int		nb_size;
	int		res_size;
	char	*res;

	nb_size = number_size(nb, get_base(flags.type), flags);
	res_size = nb_size;
	if (flags.precision == 1 && flags.max_width >= nb_size)
		res_size = flags.max_width;
	if (flags.precision == 1 && flags.max_width >= nb_size && nb <= 0)
		res_size++;
	res = strloc(res_size + 1);
	if (res == NULL)
		return (NULL);
	res = assign_int(flags, nb, res_size - 1, res);
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
		res_size = flags.max_width;
	if (flags.precision == 1 && flags.max_width >= nb_size && nb == 0)
		res_size++;
	res = strloc(res_size + 1);
	if (res == NULL)
		return (NULL);
	res = assign_int(flags, nb, res_size - 1, res);
	return (res);
}
