/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_uint.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 17:12:00 by hlin          #+#    #+#                 */
/*   Updated: 2020/01/31 17:12:02 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_put_unitstr(char *uint, t_struct flags)
{
	int		count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_spaceholder((flags.dot - 1), ((int)ft_strlen(uint) - 1), 1);
	}
	count += ft_putstr_prec(uint, (int)ft_strlen(uint));
	return (count);
}

static int	ft_put_unit(char *uint, t_struct flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
		count += ft_put_unitstr(uint, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(uint))
		flags.dot = (int)ft_strlen(uint);
	if (flags.dot >= 0)
	{
		flags.width = flags.width - flags.dot;
		count += ft_spaceholder(flags.width, 0, 0);
	}
	else
	{
		count += ft_spaceholder(flags.width, (int)ft_strlen(uint), flags.zero);
	}
	if (flags.minus == 0)
		count += ft_put_unitstr(uint, flags);
	return (count);
}

int			ft_print_uint(unsigned int n, t_struct flags)
{
	char	*str;
	int		count;

	count = 0;
	n = (unsigned int)(4294967295 + 1 + n);
	if (flags.dot == 0 && n == 0)
	{
		count += ft_spaceholder(flags.width, 0, 0);
		return (count);
	}
	str = ft_u_itoa(n);
	count += ft_put_uint(n, flags);
	free(str);
	return (count);
}
