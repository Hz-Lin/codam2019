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

t_struct	ft_struct_init(void)
{
	t_struct	flags;

	flags.printed = 0;
	flags.type = 0;
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.star =
	flags.precision = 0;
	return (flags);
}

void		ft_struct_print(t_struct *f)
{
	printf("printed:    %d\n", f->printed);
	printf("type:       %d\n", f->type);
	printf("width:      %d\n", f->width);
	printf("minus:      %d\n", f->minus);
	printf("zero:       %d\n", f->zero);
	printf("dot:        %d\n", f->dot);
	printf("width:      %d\n", f->star);
	printf("precision:  %d\n", f->precision);
}

// int			main(void)
// {
// 	t_struct	*pf;

// 	pf = NULL;
// 	pf = ft_struct_init(pf);
// 	ft_struct_print(pf);
// 	return (0);
// }
