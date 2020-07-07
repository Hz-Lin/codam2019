/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 23:37:13 by evelina       #+#    #+#                 */
/*   Updated: 2020/07/06 23:28:24 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != 0)
		{
			str += get_flags(str, args, &flags, &count);
			struct_print(&flags); //testing
			print_format(flags, args, &count);
		}
		else
		{
			count += putchar(*str);
		}
		if (count == -1)
			break ;
		str++;
	}
	va_end(args);
	return (count);
}
