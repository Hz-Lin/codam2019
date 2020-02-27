/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_format.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 15:04:00 by hlin          #+#    #+#                 */
/*   Updated: 2019/12/19 15:04:02 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		format_parser(const char *str, va_list args, t_flags *flags, int count)
{
	int		i;

	i = 1;
	while (is_type(str[i]) == 0 && str[i])
	{
		if (is_flag(str[i]) == 1 || ft_isdigit(str[i]) == 1)
			i += flags_parser((str + i), flags, args);
		else
			break ;
	}
	if (is_type(str[i]) == 1)
		flags->type = str[i];
	if (str[i] == 0)
		i--;
	check_struc(flags, count);
	return (i);
}

int		flag_parser(const char *str, t_flags *flags, va_list args)
{
	int		i;

	i = 1;
	while (format[i])
	{
		if (!ft_isdigit(format[i]) && !is_type(format[i]) && !is_flag(format[i]))
			break ;
		if (format[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[i] == '.')
			i = parse_dot(format, i, flags, args);
		if (format[i] == '-')
			*flags = parse_minus(*flags);
		if (format[i] == '*')
			*flags = parse_width(*flags, args);
		if (ft_isdigit(format[i]))
			*flags = parse_digit(*flags, format[i]);
		if (is_type(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	const char	*format_cp;
	va_list		args;
	int			count;

	format_cp = ft_strdup(format);
	count = 0;
	va_start(args, format);
	count += format_parser(format_cp, args);
	va_end(args);
	free((char*)format_cp);
	return (count);
}
