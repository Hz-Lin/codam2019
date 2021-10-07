/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/01 23:25:28 by evelina       #+#    #+#                 */
/*   Updated: 2021/04/28 17:51:34 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flags(const char *str, va_list args, t_flags *flags, int *count)
{
	int		i;

	i = 1;
	flags->type = 0;
	flags->min_width = 0;
	flags->max_width = 0;
	flags->precision = 0;
	flags->left_align = 0;
	flags->padding = ' ';
	while (str[i] && is_type(str[i]) == 0)
	{
		if (is_flag(str[i]) == 1)
			i += flags_parser(flags, (str + i), args);
		else
			break ;
	}
	if (is_type(str[i]) == 1)
		flags->type = str[i];
	if (str[i] == '\0')
		i--;
	check_struct(flags, count);
	return (i);
}

void	check_struct(t_flags *flags, int *count)
{
	if (flags->type == 0)
		*count = -1;
	if (flags->max_width < 0)
	{
		flags->precision = 0;
		flags->max_width = 0;
	}
	if (flags->min_width < 0)
	{
		flags->left_align = 1;
		flags->min_width = flags->min_width * (-1);
		flags->padding = ' ';
	}
}

int	flags_parser(t_flags *flags, const char *str, va_list args)
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
	else if (is_digit(*str) && flags->precision == 0 && flags->min_width == 0)
		flags->min_width = ft_atol(str, &size);
	else if (is_digit(*str) && flags->precision == 1 && flags->max_width == 0)
		flags->max_width = ft_atol(str, &size);
	else if (*str == '*' && flags->precision == 0 && flags->min_width == 0)
		flags->min_width = va_arg(args, int);
	else if (*str == '*' && flags->precision == 1 && flags->max_width == 0)
		flags->max_width = va_arg(args, int);
	return (size);
}
