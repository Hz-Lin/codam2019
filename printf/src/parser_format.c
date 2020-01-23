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
#include "../libft/libft.h"

int		format_parser(const char *format, va_list args)
{
	int			i;
	t_struct	flags;
	int			count;

	i = 0;
	count = 0;
	flags = ft_struct_init();
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			i = flag_parser(format, i, &flags, args);
			if (is_type(format[i]))
				count += ft_print_format((char)flags.type, flags, args);
			else if (format[i])
				count += ft_putchar(format[i]);
		}
		else if (format[i] != '%')
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	return (count);
}

int		flag_parser(const char *format, int i, t_struct *flags, va_list args)
{
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
