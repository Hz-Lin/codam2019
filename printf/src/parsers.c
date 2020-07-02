/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evelina <evelina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/01 23:25:28 by evelina       #+#    #+#                 */
/*   Updated: 2020/06/30 23:03:58 by evelina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_flags(const char *str, va_list args, t_flags *flags, int *count)
{
	int		i;

	i = 1;
	flags = struct_init(&flags);
	while (str[i] && is_type(str[i]) == 0)
	{
		if (is_flag(str[i]) == 1)
			i += flags_parser(flags, (str + i), args);
		else
			break ;
	}
	if (is_type(str[i]) == 1)
		flags->type = str[i];
	if (str[i] == 0)
		i--;
	check_struct(flags, count);
	return (i);
}

int		flags_parser(t_flags *flags, const char *str, va_list args)
{
	int		size;

	size = 1;
	if (*str == '-')
	{
		flags->left_align = 1;
		flags->padding = ' ';
	}
	else if (*str == '0' && flags->left_align == 0 && flags->precision == 0)
		flags->padding = '0';
	else if (*str == '.' && flags->precision == 0)
	{
		flags->precision = 1;
		flags->padding = ' ';
	}
	else if (ft_isdigit(*str) == 1 && flags->precision == 1 && flags->max_width == 0)
		flags->max_width = ft_atol(str, &size);
	else if (ft_isdigit(*str) == 1 && flags->precision == 0 && flags->min_width == 0)
		flags->min_width = ft_atol(str, &size);
	else if (*str == '*' && flags->precision == 0 && flags->min_width == 0)
		flags->min_width = va_arg(args, int);
	else if (*str == '*' && flags->precision == 0 && flags->max_width == 0)
		flags->max_width = va_arg(args, int);
	return (size);
}

void	format_output(t_flags flags, va_list args, int *count)
{
	char *str;

	str = NULL;
	if (flags.type == 'c' || flags.type == '%')
		str = "print char";
	if (flags.type == 's')
		str = "print str";
	if (flags.type == 'd' || flags.type == 'i')
		str = "print digit";
	if (flags.type == 'x' || flags.type == 'X' || flags.type == 'u')
		str = "print unsigned";
	if (flags.type == 'p')
		str = "print pointer";
	if (str == NULL || flags.type == 0)
	{
		*count = 1;
		return ;
	}
	print_output(str, flags, count);
}

void	print_output(char *str, t_flags flags, int *count)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(str, flags); //different len call;
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
