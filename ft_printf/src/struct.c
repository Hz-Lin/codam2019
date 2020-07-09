/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 23:39:06 by evelina       #+#    #+#                 */
/*   Updated: 2020/07/09 13:56:16 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
