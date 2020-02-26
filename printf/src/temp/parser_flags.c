/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_flags.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 11:17:28 by hlin          #+#    #+#                 */
/*   Updated: 2020/01/23 11:17:31 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

t_struct	parse_minus(t_struct flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_struct	parse_digit(t_struct flags, char c)
{
	if (flags.star == 1)
	{
		flags.width = 0;
	}
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_struct	parse_width(t_struct flags, va_list args)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int			parse_dot(const char *format, int i, t_struct *flags, va_list args)
{
	i++;
	if (format[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(format[i]))
		{
			flags->dot = (flags->dot * 10) + (format[i] - '0');
			i++;
		}
	}
	return (i);
}
