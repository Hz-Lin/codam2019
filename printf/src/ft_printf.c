/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 13:41:21 by hlin          #+#    #+#                 */
/*   Updated: 2020/02/25 13:41:23 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

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
			printf("%s\n", str); //testing
			str += format_parser(str, args, &flags, &count);
			ft_struct_print(&flags);
			// print str
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
