/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   modifier_parser.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 15:11:18 by hlin          #+#    #+#                 */
/*   Updated: 2019/12/18 15:11:19 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		parse_length(const char *format, int i, t_struct *f)
{
	while (format[i] != 'cspdiuxX%')
	{
		if (format[i] == '-')
			f->minus = 1;
		else if (format[i] == '0')
			f->zero = 1;
		else if (format[i] == '.')
			f->dot = 1;
		else if (format[i] == '*')
			printf("*");
		i++;
	}
	return (i);
}
