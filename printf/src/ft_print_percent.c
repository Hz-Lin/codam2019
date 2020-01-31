/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_percent.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 10:36:27 by hlin          #+#    #+#                 */
/*   Updated: 2020/01/29 10:36:31 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_print_percent(t_struct flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
	{
		count += ft_putstr_prec("%", 1);
	}
	count += ft_put_spacezero(flags.width, 1, flags.zero);
	if (flags.minus == 0)
	{
		count += ft_putstr_prec("%", 1);
	}
	return (count);
}
