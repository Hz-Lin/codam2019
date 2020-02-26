/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 14:01:19 by hlin          #+#    #+#                 */
/*   Updated: 2020/01/27 14:01:21 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_print_str(char *str, t_struct flags)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)(flags.dot) > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_put_part_int(str, flags); //
	if (flags.dot >= 0)
		count += ft_spaceholder(flags.width, flags.dot, 0);
	else
		count += ft_spaceholder(flags.width, flags.dot, 1);
	if (flags.minus == 0)
		count += ft_put_part_int(str, flags); //
	return (count);
}

int		ft_put_part_int(char *str, t_struct flags)
{
	int	count;

	count = 0;
	if (flags.dot = 0)
	{
		count += ft_spaceholder(flags.dot, ft_strlen(str), 0);
		count += ft_putstr_prec(str, flags.dot);
	}
	else
	{
		count += ft_putstr_prec(str, ft_strlen(str));
	}
	return (count);
}
