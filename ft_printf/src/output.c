/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/03 15:57:44 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/06 23:22:49 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int		putstr(const char *str, t_flags flags)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	if (str[i] == 0 && flags.type == 'c')
	{
		write(1, &str[i], 1);
		count++;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return (count);
}

int		cal_formatlen(const char *str, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.type == 'c' || flags.type == '%')
		return (1);
	while (str[i])
		i++;
	return (i);
}

void	print_output(char *str, t_flags flags, int *count)
{
	int	i;
	int	len;

	i = 0;
	len = cal_formatlen(str, flags);
	if (flags.type == 'p')
		len += 2;
	if (flags.left_align = 0)
	{
		while (i < flags.min_width - len)
		{
			*count += putchar(flags.padding);
			i++;
		}
	}
	if (flags.type == 'p')
		*count += putstr("0x", flags);
	*count += putstr(str, flags);
	if (flags.left_align == 1)
	{
		while (i < flags.min_width - len)
		{
			*count += putchar(flags.padding);
			i++;
		}
	}
	free(str);
}

void	print_format(t_flags flags, va_list args, int *count)
{
	char *str;

	str = NULL;
	if (flags.type == 'c' || flags.type == '%')
		str = convert_c(flags, args);
	if (flags.type == 's')
		str = convert_s(va_arg(args, char *), flags);
	if (flags.type == 'd' || flags.type == 'i')
		str = convert_int(flags, va_arg(args, int));
	if (flags.type == 'x' || flags.type == 'X' || flags.type == 'u')
		str = convert_unsigned(flags, va_arg(args, unsigned int));
	if (flags.type == 'p')
		str = convert_ulong(flags, va_arg(args, unsigned long));
	if (str == NULL || flags.type == 0)
	{
		*count = -1;
		return ;
	}
	print_output(str, flags, count);
}
