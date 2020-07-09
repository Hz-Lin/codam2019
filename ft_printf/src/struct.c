/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 23:39:06 by evelina       #+#    #+#                 */
/*   Updated: 2020/07/09 13:54:06 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// void	struct_init(t_flags *flags)
// {
// 	t_flags	flags;

// 	flags->type = 0;
// 	flags->min_width = 0;
// 	flags->max_width = 0;
// 	flags->precision = 0;
// 	flags->left_align = 0;
// 	flags->padding = ' ';
// }

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

void	struct_print(t_flags *flags)
{
	printf("type:        %c\n", flags->type);
	printf("min_width:   %d\n", flags->min_width);
	printf("max_width:   %d\n", flags->max_width);
	printf("precision:   %d\n", flags->precision);
	printf("left_align:  %d\n", flags->left_align);
	printf("padding:     %c\n", flags->padding);
}
