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

int		ft_print_char(char c, t_struct flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
	{
		ft_putchar(c);
		count = ft_parse_width(flags.width, 1, 0); // ft_treat_width
	}
	if (flags.minus == 0)
	{
		ft_putchar(c);
	}
	return (count + 1);
}
