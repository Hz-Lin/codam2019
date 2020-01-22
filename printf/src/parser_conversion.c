/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_conversion.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 17:15:13 by hlin          #+#    #+#                 */
/*   Updated: 2020/01/07 17:15:16 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		is_type(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int		is_flag(int c)
{
	if (c == '-' || c == ' ' || c == '0' || c == '.' || c == '*')
		return (1);
	else
		return (0);
}

int		ft_print_format(int c, t_struct flags, va_list args)
{
	int		count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(args, int), flags);
	else if (c == 's')
		count = ft_print_str(va_arg(args, char *), flags);
	else if (c == 'p')
		count = ft_print_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		count = ft_print_int(va_arg(args, int), flags);
	else if (c == 'u')
		count += ft_print_uint((unsigned int)va_arg(args, unsigned int), flags);
	else if (c == 'x')
		count += ft_print_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_print_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		count += ft_print_percent(flags);
	return (count);
}
