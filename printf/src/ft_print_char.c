/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 16:04:17 by hlin          #+#    #+#                 */
/*   Updated: 2020/01/22 16:04:18 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int		ft_print_char(char c, t_struct flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
	{
		ft_putchar(c);
		count = cal_width(flags.width, 1, 0);
	}
	if (flags.minus == 0)
	{
		ft_putchar(c);
	}
	return (count + 1);
}

int		cal_width(int width, int minus, int zero)
{
	int		count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		count++;
	}
	return (count);
}
