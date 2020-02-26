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

t_flags	*ft_struct_init(t_flags *flags)
{
	t_flags	flags;

	flags->type = 0;
	flags->min_width = 0;
	flags->max_width = 0;
	flags->precision = 0;
	flags->left_align = 0;
	flags->padding = ' ';
	return (flags);
}

void	ft_struct_print(t_flags *flags)
{
	printf("type:        %c\n", flags->type);
	printf("min_width:   %d\n", flags->min_width);
	printf("max_width:   %d\n", flags->max_width);
	printf("precision:   %d\n", flags->precision);
	printf("left_align:  %d\n", flags->left_align);
	printf("padding:     %c\n", flags->padding);
}

// int	main(void)
// {
// 	t_struct	*pf;

// 	pf = NULL;
// 	pf = ft_struct_init(pf);
// 	ft_struct_print(pf);
// 	return (0);
// }
