/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_parser.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 11:49:26 by hlin          #+#    #+#                 */
/*   Updated: 2019/12/13 11:49:28 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

int		format_parser(const char *format)
{
	int		re_val;
	int		i;

	re_val = 0;
	i = 0;
	while (*format != '\0' && *format != '%')
	{
		ft_putchar_fd((char)(*format), 1);
		format++;
		re_val++;
	}
	if (*format == '%')
	{
		format++;
		if (ft_strchr("#0 +-", (char)(*format)))
		{
			printf("This is a flag");
		}
	}

	printf("%d\n", re_val);
	return (re_val);
}

int		main()
{
	format_parser("Hello %d world %c");
	return (0);
}
