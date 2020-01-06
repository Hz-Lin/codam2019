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

int		format_parser(const char *format) //t_struct *f, va_list pf_arg
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		printf("i: %d\n", i);
		if (format[i] == '%')
		{
			i++;
			while (!ft_strchr("cspdiuxX%", format[i]))
			{
				printf("modifier: %c\n", format[i]);
				i++;
			}
			printf("conversions: %c\n", format[i]);
			i++;
		}
		count = write(1, &format[i], 1);
		printf("\n");
		i++;
	}
	return (count);
}

// void	ft_print_arg(const char *format, struct s_pf t_pf, va_list pf_arg)
// {
// 	if (format[t_pf.conv] == 'd' || format[t_pf.conv] == 'i')
// 		printf("integer");
// 	if (format[t_pf.conv] == 'd' || format[t_pf.conv] == 'i')
// 		printf("integer");
// }

int		main(void)
{
	format_parser("Hello %d world %c test");
	return (0);
}
