/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 17:30:01 by hlin          #+#    #+#                 */
/*   Updated: 2020/01/29 17:30:04 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_intstr(char *str, int n, t_struct flags)
{
	int		count;

	count = 0;
	if (n < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += cal_width((flags.dot - 1), ((int)ft_strlen(str) - 1), 1);
	count += ft_putstrprec(str, (int)ft_strlen(str));
	return (count);
}

static int	print_intstr_struct(char *str, int n, t_struct flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
		count += print_intstr(str, n, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = (int)ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += cal_width(flags.width, 0, 0);
	}
	else
	{
		count += cal_width(flags.width, (int)ft_strlen(str), flags.zero);
	}
	if (flags.minus == 0)
		count += print_intstr(str, n, flags);
	return (count);
}

int			ft_print_int(int n_int, t_struct flags)
{
	char	*n_str;
	int		n_copy;
	int		count;

	n_copy = n_int;
	count = 0;
	if (flags.dot == 0 && n_int == 0)
	{
		count += cal_width(flags.width, 0, 0);
		return (count);
	}
	if (n_int < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == 1)
			ft_putstrprec("-", 1);
		n_int = -1 * n_int;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	n_str = ft_itoa(n_int);
	count = print_intstr_struct(n_str, n_copy, flags);
	free(n_str);
	return (count);
}
