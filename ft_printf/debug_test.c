/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 15:32:28 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/10 00:40:19 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("or:%s\n", "");
	ft_printf("or:%s\n", "");
	printf("or:%X\n", 0);
	ft_printf("or:%X\n", 0);
	return (0);
}
