/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_debug.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 16:45:09 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/08 18:12:06 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int     main(void)
{
	printf("or:%-10.5d\n", -216);
	ft_printf("ft:%-10.5d\n", -216);
	return (0);
}
