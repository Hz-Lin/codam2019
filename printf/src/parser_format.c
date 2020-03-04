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

int		format_parser(const char *str, va_list args, t_flags *flags, int *count)
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
	int		size;

	size = 1;
	if (*str == '-')
	{
		flags->left_align = 1;
		flags->padding = ' ';
	}
	else if (*str == '0' && flags->left_align == 0 && flags->precision == 0)
		flags->padding == '0';
	else if (*str == '.' && flags->precision == 0)
	{
		flags->precision = 1;
		flags->padding = ' ';
	}
	else if (flags->precision == 1 && ft_isdigit(*str) == 1 && flags->max_width == 0)
		flags->max_width = ft_atoi_long(str, &size);//
	else if (flags->precision == 0 && ft_isdigit(*str) == 1 && flags->min_width == 0)
		flags->min_width = ft_atoi_long(str, &size);//
	else if (flags->precision == 1 && *str == '*' && flags->max_width == 0)
		flags->max_width = va_arg(args, int);
	else if (flags->precision == 0 && *str == '*' == 1 && flags->min_width == 0)
		flags->min_width = va_arg(args, int);
	return (size);
}

void	make_string(t_flags *flags, va_list args, int *count)
{
	char	*str;

	str = NULL;
	if (flags->type == 0)
		return ;
	if (flags->type == 'c' || flags->type == '%')
	{
		str = (char *)ft_malloc_str(2);
		str[0] = flags->type;
		if (flags->type == 'c')
			str[0] = va_arg(args, int);
		str[1] = 0;
	}
}

char	*ft_malloc_str(int len)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(sizeof(char) * len);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
