/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/01 23:25:28 by evelina       #+#    #+#                 */
/*   Updated: 2020/07/06 23:26:41 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			is_type(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' | c == 'u')
		return (1);
	else if (c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int			is_flag(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	else if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

long long	ft_atol(const char *str, int *size)
{
	long long			neg;
	unsigned long long	res;
	int					i;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	*size += (i - 1);
	return (res * neg);
}

int			get_flags(const char *str, va_list args, t_flags *flags, int *count)
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
	if (str[i] == 0)
		i--;
	check_struct(flags, count);
	return (i);
}

int			flags_parser(t_flags *flags, const char *str, va_list args)
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
	else if (ft_isdigit(*str) && flags->precision == 1 && flags->max_width == 0)
		flags->max_width = ft_atol(str, &size);
	else if (ft_isdigit(*str) && flags->precision == 0 && flags->min_width == 0)
		flags->min_width = ft_atol(str, &size);
	else if (*str == '*' && flags->precision == 0 && flags->min_width == 0)
		flags->min_width = va_arg(args, int);
	else if (*str == '*' && flags->precision == 1 && flags->max_width == 0)
		flags->max_width = va_arg(args, int);
	return (size);
}
