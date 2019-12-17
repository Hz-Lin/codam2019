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

void	ft_reset_spf(struct s_pf t_pf)
{
	t_pf.minus = 0;
	t_pf.plus = 0;
	t_pf.space = 0;
	t_pf.zero = 0;
	t_pf.hashtag = 0;
	t_pf.width = 0;
	t_pf.precision_sp = 0;
	t_pf.precision = 0;
	t_pf.length = 0;
}

int		format_parser(const char *format, struct s_pf t_pf, va_list pf_arg)
{
	while (format[t_pf.conv] != '\0')
	{
		if (format[t_pf.conv] != '%')
		{
			t_pf.conv++;
			if (ft_strchr("#-+ .*0123456789hljz", format[t_pf.conv]))
				printf("parse modifiers");
			if (ft_strchr("cspdiuxX%nfge", format[t_pf.conv]))
			{
				printf("call ft_printf to print format with the struct");
				if (t_pf.len == -1)
					return ;
				ft_reset_spf(t_pf);
			}
		}
		else
		{
			t_pf.len = write(t_pf.fd, &format[t_pf.conv], 1);
		}
		t_pf.conv++;
	}
}

void	ft_print_arg(const char *format, struct s_pf t_pf, va_list pf_arg)


int		main(void)
{
	format_parser("Hello %d world %c");
	return (0);
}
