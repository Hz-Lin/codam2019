/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 23:37:13 by evelina       #+#    #+#                 */
/*   Updated: 2020/07/10 00:40:25 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str += get_flags(str, args, &flags, &count);
			print_format(flags, args, &count);
		}
		else
		{
			count += ft_putchar(*str);
		}
		if (count == -1)
			break ;
		str++;
	}
	va_end(args);
	return (count);
}
