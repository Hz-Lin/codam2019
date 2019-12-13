/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 17:20:27 by hlin          #+#    #+#                 */
/*   Updated: 2019/12/11 17:20:32 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

int		arg_parser(const char *format, ...)
{
	va_list	arg;
	va_list	arg_cp;
	char	*str;
	int		len;
	int		arg_count;

	len = 0;
	arg_count = 0;
	va_start(arg, format);
	va_copy(arg_cp, arg);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			str = va_arg(arg, char*);
			printf("argument is: %s\n", str);
			arg_count++;
		}
		format++;
		len++;
	}
	printf("arguments count: %d\n", arg_count);
	while (arg_count > 0)
	{
		printf("argument copy is: %s\n", va_arg(arg_cp, char*));
		arg_count--;
	}
	va_end(arg);
	return (len);
}

int		main(void)
{
	int		count;

	count = arg_parser("4 arg: %s %s %s", "This", "is", "Test");
	printf("return value: %d\n", count);
}
