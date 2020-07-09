/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_debug.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 16:45:09 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/09 13:59:15 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int     main(void)
{
	// printf("or:%-10.5d\n", -216);
	// ft_printf("ft:%-10.5d\n", -216);
	// printf("or:this is %d\n", -267);
	// ft_printf("ft:this is %d\n", -267);
	// printf("or:%d\n", -1);
	// ft_printf("ft:%d\n", -1);
	// printf("or:%d\n", 0);
	// ft_printf("ft:%d\n", 0);

	// printf("or:%.3u\n", 0);
	// ft_printf("ft:%.3u\n", 0);
	// printf("or:8.5u\n", 0);
	// ft_printf("ft:8.5u\n",0);
	// printf("or:-8.5u\n", 0);
	// ft_printf("ft:-8.5u\n", 0);
	// printf("or:08.5u\n", 0);
	// ft_printf("ft:08.5u\n",0);

	printf("or:%p\n", NULL);
	ft_printf("ft:%p\n", NULL);
	// // printf("or:%.5p\n", 0);
	// // ft_printf("ft:%.5p\n", 0);

	// printf("or:%8.5x\n", 0);
	// ft_printf("ft:%8.5x\n", 0);
	// // printf("or:%.x\n", 0);
	// ft_printf("ft:%.x\n", 0);

	printf("or:%0*i\n", -7, -54);
	ft_printf("ft:%0*i\n", -7, -54);

	return (0);
}
