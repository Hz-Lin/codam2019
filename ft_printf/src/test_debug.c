/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_debug.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 16:45:09 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/09 11:19:25 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int     main(void)
{
	printf("or:%-10.5d\n", -216);
	ft_printf("ft:%-10.5d\n", -216);
	printf("or:this is %d\n", -267);
	ft_printf("ft:this is %d\n", -267);
	printf("or:%d\n", -1);
	ft_printf("ft:%d\n", -1);
	printf("or:%d\n", 0);
	ft_printf("ft:%d\n", 0);
	return (0);
}
